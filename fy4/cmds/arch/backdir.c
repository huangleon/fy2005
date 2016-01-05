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
        	return notify_fail("���Ķ����������������ƻ��ԡ�\n");
        	
        seteuid(getuid());
        files=read_table("change.txt");
		write("\n");
		for (i=0; i<sizeof(files); i++)
			analysis(files[i]);
		write(HIY+(b+c)+HIC"�����������֣�"HIY+b+HIC"����������ɹ���"HIY+c+HIC"����������ʧ�ܡ�\n"NOR);

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
			write(HIG"û��"+a+"���������\n"NOR);
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
		write(HIW"����"+a+"�ѳɹ�����\n"NOR);
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
			write(HIG"�˵�����Ϊ�ա�\n"NOR);
		else
			write(HIG"�˵����в����ڡ�\n"NOR);
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
	write(HIB+a+"�����д�����ϡ�\n"NOR);
	return 0;
}


int help(object me)
{
   write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	backdir yesiknow[0m
[0;1;37m����������������������������������������������������������������[0m   

����ָ�Ϊtttt�ķ����������㲻�Ǹ����ļ����£��벻Ҫʹ�ô����

[0;1;37m����������������������������������������������������������������[0m   

HELP
   );
   return 1;
}
/*

������     /��              ��\      
������   ��   �ܣߣߡ�������  ��       
������   �� ����    ���������v��       
������    �M                  ��       
������    ��   /��\    /��\   ��      
������    ��   ����    ��  �� ��       
������   ��    \ /    \��/    ��      
������    ����      ��      ���M         
������    ���v��    ��   ������         
������    �q������������������           
������   ��   ��           /���\����    
������  ��____��  �� ��  �� .. ����     
������        \���/ ����ܡ�         
                       ��             
����������������- FengYun - ������
 ��������������annie 06.2005
 ��������dancing_faery@hotmail.com

*/
