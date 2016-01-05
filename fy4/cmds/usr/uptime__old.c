// uptime.c
//	µ±µØÊ±¼ä modified from hy2002, credit goes to whoever created it.
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

	if(d) time = chinese_number(d) + "Ìì";
	else time = "";

	if(h) time += chinese_number(h) + "Ğ¡Ê±";
	if(m) time += chinese_number(m) + "·Ö";
	time += chinese_number(s) + "Ãë";
	mudver = read_file("/doc/help/version.txt");
	if(!stringp(mudver)) {
		mudver = "CAN NOT READ FILE version.txt\n";	
	}
	mudver = replace_string(mudver, "\n","");
	write(GRN "·çÔÆ2005£¨"+mudver+"£©ÒÑ¾­ÔËĞĞÁË" + time + "¡£\n" NOR);
	write("·çÔÆÊ±¼ä" + NATURE_D->game_time() + "¡£\n");
	write("·çÔÆÕ¾µ±µØÊ±¼ä" + chinese_time(5,""+time()) + "¡£\n\n");
	
	x = "/d/fy/fysquare"->refresh();
	if (x>0 && x!=99999)
		write ("ÏµÍ³»¹ÓĞ"+ (x/60)+"·Ö"+ (x%60) +"Ãë¸üĞÂ£¬Îó²îÕı¸º30ÃëÖÓ¡£\n");
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

        c_year = c_year + "Äê";
        c_month  = c_month + "ÔÂ";
        c_week = " ĞÇÆÚ"+c_week;

        c_time = chinese_number(day) + "ÈÕ";
        c_time += chinese_number(hour) + "µã";
        c_time += chinese_number(minute) + "·Ö";
        // maybe not need srcond to show
        // c_time += chinese_number(second) + "Ãë";

        if (type) {
                switch( type ) {
                        case 7: return year+"Äê"+(member_array(month, month_name) + 1)+"ÔÂ"+day+"ÈÕ";
                        case 1: return c_year+c_month+c_time+c_week;
                        case 2: return c_year+c_month+c_time;
                        case 3: return c_month+c_time+c_week;
                        case 4: return c_month+c_time;
                        case 5: return year+"Äê"+(member_array(month, month_name) + 1)+
				"ÔÂ"+day+"ÈÕ"+hour+"µã"+minute+"·Ö";
                        case 6: return (member_array(month, month_name) + 1)+
				"ÔÂ"+day+"ÈÕ"+hour+"µã"+minute+"·Ö";
                        default: return c_year+c_month+c_time+c_week;
                        }
                }
        return c_year+c_month+c_time+c_week;
}

int help(object me)
{
	write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	uptime
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

Õâ¸öÖ¸Áî¸æËßÄãÏÖÔÚ·çÔÆÊÀ½çµÄÊ±¼ä£¬Õ¾µãµÄµ±µØÊ±¼ä£¬
·çÔÆµÄ°æ±¾ºÍÁ¬ĞøÔËĞĞµÄÊ±¼ä¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m 
HELP
    );
    return 1;
}
