import re

class CgaSort:

    def __init__(self):
        """initialize important data structures"""
        self.regx_hour_num = re.compile('(?P<hour>\d{1,2}(:\d\d)?[a|p]m)')
        self.regx_hour_colloq = re.compile('(?P<colloq>noon|midnight)')
        self.regx_early_late = re.compile('pm$')
        self.regx_station = re.compile('[a-z]{3,4} ')
        self.showtimes = []

    def FindDay(self, data_str):
        result = 0
        data_str = data_str.lower()
        if data_str.find('sunday') != -1:
            result = 0
        elif data_str.find('monday') != -1:
            result = 1
        elif data_str.find('tuesday') != -1:
            result = 2
        elif data_str.find('wednesday') != -1:
            result = 3
        elif data_str.find('thursday') != -1 or data_str.find('th') != -1:
            result = 4
        elif data_str.find('friday') != -1:
            resut = 5
        elif data_str.find('saturday') != -1:
            result = 6
        else:
            raise Exception('could not find day of week: ' + data_str)
        return result

    def FindTime(self, token):
        """ascertain the hour of day in military time style (sort of)"""
        time = ''
        if token == 'noon':
            time = '12'
        elif token == 'midnight':
            time = '0'
        else:
            late = False
            if self.regx_early_late.search(token) != None:
                late = True
            token = token[0:len(token)-2]
            colon_index = token.find(':')
            if colon_index != -1:
                token = token[0:colon_index]
            if len(token) == 3:   # special case for 600pm
                token = token[0]
            time = int(token)
            if late and time != 12:
                time += 12
        return time
                
    def ProcessDateTime(self, token, line, previous_line):
        """define a function to normalize the show times"""
        #self.showtimes.append(line)
        time = self.FindTime(token)
        day = self.FindDay(line)
        final_line = line
        if self.regx_station.match(line.lower()) == None:
            final_line = previous_line + ' --- ' + line
        self.showtimes.append((day, time, final_line))

    def ProcessInputFile(self):
        """process the input file line by line"""
        previous_line = ''
        handle = open('cga.txt', 'r')
        for line in handle:
            found_hit = False
            line = line.rstrip()
            temp_line = line.lower()
            matchobj = self.regx_hour_num.search(temp_line)
            if matchobj != None:
                self.ProcessDateTime(matchobj.group('hour'), line, previous_line)
            else:
                matchobj = self.regx_hour_colloq.search(temp_line)
                if matchobj != None:
                    self.ProcessDateTime(matchobj.group('colloq'), line, previous_line)
            previous_line = line

    def GetTimeIndex(self, record):
        """define a comparator to assist in sorting the showtimes"""
        day = int(record[0])
        time = int(record[1])
        return (day * 24) + time

    def Sort(self):
        self.showtimes = sorted(self.showtimes, key=self.GetTimeIndex)
        
    def Output(self):
        """output the results"""
        for record in self.showtimes:
            print(record)
        #print(showtimes)
        #for key in showtimes.keys():
        #    print(key + ' --- ' + showtimes[key])


if __name__ == "__main__":
    sortobj = CgaSort()
    sortobj.ProcessInputFile()
    sortobj.Sort()
    sortobj.Output()
