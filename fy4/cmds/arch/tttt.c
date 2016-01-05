           // Annie. 2005 
// Dancing_Faery@HOTMAIL.COM


#include "/doc/help.h"
#include <ansi.h>

inherit F_CLEAN_UP;
string* files;
string *read_table(string file);
int update_function(object me, string file);
int analysis(string a);
int deep_analysis(string a);

int b=0,c=0,d=0,e=0;

int main(object me, string arg)
{
        int i,a;
        
#ifdef	ENCRYPTED_WRITE	
		return notify_fail("������ֻ���ڣ���վ�����Ҫ���С�\n");
#endif        
        seteuid(getuid());
        files=read_table("change.txt");
        b=0;c=0;d=0;e=0;
        write("\n");
        for (i=0; i<sizeof(files); i++) {
        	if (i%100 == 0) 
        		reset_eval_cost();
        	analysis(files[i]);
		}
		
       	write(HIY+(b+c)+HIC"�����������֣�"HIY+b+HIC"����������ɹ���"HIY+c+HIC"����������ʧ�ܡ�\n"NOR);
       	write(HIC"��"+HIY+e+HIC"������δͨ�����롣\n"NOR);

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
                log_file("tttt","û��"+a+"���������\n"); 
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

        if (update_function(this_player(),a+ext))
        {
                d++;
        }
        else
        {
                e++;
                write(HIR"����"+a+"����ʧ�ܡ�\n"NOR);
                log_file("tttt","����"+a+"����ʧ�ܡ�\n"); 
        }
        
        if (cp(a+ext,"/bunny"+a+ext))
                write(HIW"����"+a+"�ѳɹ�����\n"NOR);
        b++;
        return 1;
        
}






int update_function(object me, string file)
{
        int i;
        object obj, *inv;
        string err;

        seteuid( geteuid(me) );

        if (!file) file = me->query("cwf");
        if (!file)
                return notify_fail("��Ҫ���±���ʲ�ᵵ����\n");

                file = resolve_path(me->query("cwd"), file);
                if( !sscanf(file, "%*s.c") ) file += ".c"; 

        if( file_size(file)==-1 )
                return notify_fail("û�����������\n");

        me->set("cwf", file);

        if (obj = find_object(file)) {
                if( obj==environment(me) ) {
                        if( file_name(obj)==VOID_OB )
                                return notify_fail("�㲻���� VOID_OB �����±��� VOID_OB��\n");
                }

                inv = all_inventory(obj);
                i = sizeof(inv);
                while(i--) {
                        if(userp(inv[i])) {
                                inv[i]->move(VOID_OB, 1);
                        } else {
                                destruct(inv[i]);
                        }
                }

                destruct(obj);
        }

        if (obj) return notify_fail("�޷�����ɳ�ʽ�롣\n");

//      write("���±��� " + file + "��");
        err = catch( call_other(file, "???") );
        if (err)
                {
        		write(HIR"�ڱ��� " + file + "ʱ");
                	printf( "��������\n%s\n"NOR, err );
           		log_file("tttt","����"+file+"ʧ�ܣ���������\n"); 
                        }
        else {
//                write("�ɹ���\n");
                log_file( "UPDATE_LOG", sprintf("(%s)
%s updated %s\n", ctime(time()), me->query("name"), file));
        
                if( (i=sizeof(inv)) && (obj = find_object(file))) {
                        while(i--)
                                if( inv[i] && userp(inv[i]) ) 
                                        inv[i]->move(obj, 1);
                }
        }
                
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
                if (file_size(a) == -2) {
                        write(HIG+a+"������Ϊ�ա�\n"NOR);
                		log_file("tttt",a+"������Ϊ�ա�\n"); 
                }
                else	{
                        write(HIG+a+"�����в����ڡ�\n"NOR);
                        log_file("tttt",a+"�����в����ڡ�\n"); 
                }        
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
[0;1;36m��ʦָ���ʽ : 	tttt[0m
[0;1;37m����������������������������������������������������������������[0m   

����ָ���������Ŀ¼���ļ�change.txt���б��ļ�ת��/bunny��

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

