// Annie. 2005 
// Dancing_Faery@HOTMAIL.COM


#include "/doc/help.h"
#include <ansi.h>

inherit F_CLEAN_UP;
string* files;
string *read_table(string file);
int analysis(string a);
int deep_analysis(string a);

int b=0,c=0;

int main(object me, string arg)
{
		int i,a;
        b=0;
        c=0;
        
        if (arg != "yesiknow")
        	return notify_fail("ÇëÔÄ¶Á°ïÖú£¬´ËÃüÁîÓĞÆÆ»µĞÔ¡£\n");
        	
        seteuid(getuid());
        files=read_table("change.txt");
		write("\n");
		for (i=0; i<sizeof(files); i++)
			analysis(files[i]);
		write(HIY+(b+c)+HIC"¸öµµ°¸±»·¢ÏÖ£¬"HIY+b+HIC"¸öµµ°¸´¦Àí³É¹¦£¬"HIY+c+HIC"¸öµµ°¸´¦ÀíÊ§°Ü¡£\n"NOR);

        write("Ok.\n");
        return 1;
}


string *read_table(string file)
{
        string *line, *field, *format;
        string *data;
        int i, rn, fn;
        data = ({});
		if (read_file(file))
		{
			line = explode(read_file(file), "\n");
			for( i=0; i<sizeof(line); i++)
			{
					if( line[i]=="" || line[i][0]=='#' ) continue;
					data+=({line[i]});
			}
		}
        return data;

}

int analysis(string a)
{
	string* dirs;
	string tmp;
	int i;
	string ext = ".c";

	reset_eval_cost();

	if (a[0] == '!')
	{
		ext="";
		a=a[1..];
	}

	if (a[0] == '@')
	{
		//
		return deep_analysis(a[1..]);
	}

	if( file_size(a+ext) < 0 )
	{
			write(HIG"Ã»ÓĞ"+a+"Õâ¸öµµ°¸¡£\n"NOR);
			c++;
			return 0;
	}

	dirs = explode(a, "/");
	mkdir("bunny");
	tmp="bunny/";
	for (i=0;i<sizeof(dirs)-1;i++)
	{
		tmp += dirs[i];
		mkdir(tmp);
		tmp += "/";
	}

	if (cp(a+ext,"/bunny"+a+ext))
		write(HIW"µµ°¸"+a+"ÒÑ³É¹¦´¦Àí¡£\n"NOR);
	b++;
	return 1;
	
}


int deep_analysis(string a)
{
	// get file list first;
	mixed *file;
	int i;

	reset_eval_cost();
	file = get_dir(a, -1);
	if( !sizeof(file) )
	{
		if (file_size(a) == -2)
			write(HIG"´Ëµµ°¸¼ĞÎª¿Õ¡£\n"NOR);
		else
			write(HIG"´Ëµµ°¸¼Ğ²»´æÔÚ¡£\n"NOR);
		c++;
		return 0;
	}

	i = sizeof(file);
	while(i--) 
	{
		if (file[i][1]==-2) 
		{
			deep_analysis(a+file[i][0]+"/");
			continue;
		}
		analysis("!"+a+file[i][0]);
	}
	write(HIB+a+"µµ°¸¼Ğ´¦ÀíÍê±Ï¡£\n"NOR);
	return 0;
}


int help(object me)
{
   write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÎ×Ê¦Ö¸Áî¸ñÊ½ : 	backdir yesiknow[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

µ÷ÊÔÖ¸Áî£¬ÎªttttµÄ·´ÏòÃüÁî£¬Èç¹ûÄã²»ÊÇ¸ºÔğÎÄ¼ş¸üĞÂ£¬Çë²»ÒªÊ¹ÓÃ´ËÃüÁî¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

HELP
   );
   return 1;
}
/*

¡¡¡¡¡¡     /£Ü              £¯\      
¡¡¡¡¡¡   ¨Š   £Ü£ß£ß¡¡¡¡¡¡£¯  ¦ò       
¡¡¡¡¡¡   ¨Š £¯£ş    ¨¨€¨€¨¨v¦ò       
¡¡¡¡¡¡    ¨M                  ©…       
¡¡¡¡¡¡    ¦ô   /£ş\    /£ş\   ¨Š      
¡¡¡¡¡¡    ¦ô   ¦ô¡ñ    ¡ñ  ¦ô ¨Š       
¡¡¡¡¡¡   ©à    \ /    \¡¡/    ©à      
¡¡¡¡¡¡    ©…¡¡      ¡ñ      ¡¡¨M         
¡¡¡¡¡¡    ¡¥¨v¡¡    ¡¡   ¡¡£¯¡¥         
¡¡¡¡¡¡    ¨q©¤¨¡¥¡¥¡¥£ş¨¨©…           
¡¡¡¡¡¡   £¨   ¦ô           /¦å¦å\¨¨€    
¡¡¡¡¡¡  £¨____¦ô  ¨Š £¯  ¨Š .. ¨€¨     
¡¡¡¡¡¡        \¦ä¦ä/ ¦ã¦ã¦ã£Ü¡ñ£¯         
                       ¡¥             
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡- FengYun - ¡¡¡¡¡¡
 ¡¡¡¡¡¡¡¡¡¡¡¡¡¡annie 06.2005
 ¡¡¡¡¡¡¡¡dancing_faery@hotmail.com

*/
