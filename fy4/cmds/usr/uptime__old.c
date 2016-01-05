// uptime.c
//	����ʱ�� modified from hy2002, credit goes to whoever created it.
//		--- Silencer@fy4

inherit F_CLEAN_UP;
#include <ansi.h>
// This command is also called by LOGIN_D, so we don't want it use 
// arguments.
string chinese_time(int type,string get_time);

int main()
{
	int t, d, h, m, s,x;
	string time;
	string mudver;
	t = uptime();
	s = t % 60;		t /= 60;
	m = t % 60;		t /= 60;
	h = t % 24;		t /= 24;
	d = t;

	if(d) time = chinese_number(d) + "��";
	else time = "";

	if(h) time += chinese_number(h) + "Сʱ";
	if(m) time += chinese_number(m) + "��";
	time += chinese_number(s) + "��";
	mudver = read_file("/doc/help/version.txt");
	if(!stringp(mudver)) {
		mudver = "CAN NOT READ FILE version.txt\n";	
	}
	mudver = replace_string(mudver, "\n","");
	write(GRN "����2005��"+mudver+"���Ѿ�������" + time + "��\n" NOR);
	write("����ʱ��" + NATURE_D->game_time() + "��\n");
	write("����վ����ʱ��" + chinese_time(5,""+time()) + "��\n\n");
	
	x = "/d/fy/fysquare"->refresh();
	if (x>0 && x!=99999)
		write ("ϵͳ����"+ (x/60)+"��"+ (x%60) +"����£��������30���ӡ�\n");
	return 1;
}

string chinese_time(int type,string get_time)
{
        string e_time, week, month, year;
        string c_week, c_year, c_month, c_time;
        int day, hour, minute, second;
        string *month_name = ({"Jan","Feb","Mar","Apr","May","Jun","Jul",
		"Aug","Sep","Oct","Nov","Dec"});
        string *week_name = ({"Mon","Tue","Wed","Thu","Fri","Sat","Sun"});

        e_time = ctime(atoi(get_time));

        // e_time must is ctime(time string) like "Sun May  3 00:52:12 1998"
        sscanf(e_time,"%s %s %d %d:%d:%d %s", week, month, day, hour, minute, second, year);

        c_week  = chinese_number(member_array(week, week_name) + 1);
        c_month = chinese_number(member_array(month, month_name) + 1);

        c_year  = sprintf("%s%s%s%s",
                         chinese_number(year[0]-48),
                         chinese_number(year[1]-48),
                         chinese_number(year[2]-48),
                         chinese_number(year[3]-48));

        c_year = c_year + "��";
        c_month  = c_month + "��";
        c_week = " ����"+c_week;

        c_time = chinese_number(day) + "��";
        c_time += chinese_number(hour) + "��";
        c_time += chinese_number(minute) + "��";
        // maybe not need srcond to show
        // c_time += chinese_number(second) + "��";

        if (type) {
                switch( type ) {
                        case 7: return year+"��"+(member_array(month, month_name) + 1)+"��"+day+"��";
                        case 1: return c_year+c_month+c_time+c_week;
                        case 2: return c_year+c_month+c_time;
                        case 3: return c_month+c_time+c_week;
                        case 4: return c_month+c_time;
                        case 5: return year+"��"+(member_array(month, month_name) + 1)+
				"��"+day+"��"+hour+"��"+minute+"��";
                        case 6: return (member_array(month, month_name) + 1)+
				"��"+day+"��"+hour+"��"+minute+"��";
                        default: return c_year+c_month+c_time+c_week;
                        }
                }
        return c_year+c_month+c_time+c_week;
}

int help(object me)
{
	write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	uptime
[0;1;37m����������������������������������������������������������������[0m   

���ָ����������ڷ��������ʱ�䣬վ��ĵ���ʱ�䣬
���Ƶİ汾���������е�ʱ�䡣

[0;1;37m����������������������������������������������������������������[0m 
HELP
    );
    return 1;
}
