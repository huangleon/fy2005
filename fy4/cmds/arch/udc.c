// udc.c annie 07.2003
// dancing_faery@hotmail.com
// ����һ��CLASS�µ�һ���ļ�
// ��"-o"������/DAEMON/SKILL��/DAEMON/CONDITION�е�һ���ļ�
// һ�������ǲ���Ҫsilencer����̽����ÿ��directory������ޣ���һ������Ҫ��updatep���㡣

#include <ansi.h>
inherit F_CLEAN_UP;

int error;

int update_function(object me, string file);

int main(object me,string arg)
{
	string *files;
	mixed *file;
	int i,j,w=0,col,total=0;
	int size;
	set_eval_limit(1); 
	seteuid(getuid());
	if(!arg || arg=="") return notify_fail("��ʽ���ԣ�\n");

	error = 0;

	if (arg == "-o")
		arg = "/daemon/";
	else
		arg = "/daemon/class/"+arg+"/";
    
	file = get_dir(arg, -1);
   	reset_eval_cost();
	if( !sizeof(file) )
	{if (file_size(arg) == -2) return notify_fail("�ĵ����ǿյġ�\n");
		else
		return notify_fail("û������ĵ��С�\n");
	}

	write(HIW"������Ѳ"+arg+"�ĵ��У�����\n"NOR);

	i = sizeof(file);
	w = 0;
	while(i--) {
		if (file[i][1]==-2) 
		{
			files = get_dir(arg+file[i][0]+"/");
		   	reset_eval_cost();
			// �ţ����Ӧ���Ƕ�Ӧ��skill�ĵ���һ������
			update_function(me,"/daemon/skill/"+file[i][0]);
			// is a directory , ��׷��һ�㡣
			for(j=0; j<sizeof(files); j++) 
			{
				size=sizeof(files[j]);
				if(files[j][(size-2)..size]==".c")
				{
					update_function(me,arg+file[i][0]+"/"+files[j]);
					total++;
				}
			}   	 	
			file[i][0] += "/";
		}
	}
	write(HIW"������"+arg+"�ĵ��б�����ɡ�\n����������Ѳ��"+total+"������������"+error+"������ʧ�ܡ�\n"NOR);

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

    	write("���±��� " + file + "��");
        err = catch( call_other(file, "???") );
        if (err)
		{
			error++;
                printf( "��������\n%s\n", err );
			}
        else {
                write("�ɹ���\n");
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


int help(object me)
{
        write(@HELP
[0;1;37m������������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	udc [CLASS��] [-o]	[0m
[0;1;37m������������������������������������������������������������������[0m   

udc demon	��������/daemon/class/demon/�µ��ļ����Ӧskills��
udc -o		��������/daemon/skill��/daemon/condition�µ��ļ���

[0;1;37m������������������������������������������������������������������[0m 
HELP
    );
    return 1;
}
