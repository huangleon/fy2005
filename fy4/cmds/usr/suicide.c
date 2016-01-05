#include <ansi.h>

int rmhirdir(string dir);

int main(object me, string arg)
{
    	if( me->is_busy() )
        	return notify_fail("����һ��������û��ɡ�\n");

    	if( !arg )
    	{
        	write("������ɱ���������������²����֡�\n");
        	return 1;
    	}

    	if( arg!="-f" ) 
        	return notify_fail("��ɱ�����֣�����Ҫ��Զ������������Ͷ̥��\n");

//		if (wizardp(me))
//		return notify_fail("������Ա��������ɱ��\n");
		
		if (me->query("combat_exp")< 4000)
			return notify_fail("��ľ���ֵ̫�ͣ�ϵͳ����������������ɱ���˳����ǡ�\n");
		
    if (me->query("combat_exp")>= 2100000)
    	return notify_fail("
���ڷ�����С���������Ѿ�û��������ɱ�ˡ����ȼ�����50��
���ƽ��ڲ��õĽ����Ƴ�����ϵͳ���������ϴ�֣����𽭺���Ϊ�������������Ļ��䡣\n");
    	
    write(HIR"�����ѡ����Զ��������ɱ��ʽ���������Ͼ���Զɾ���ˣ�һ��\n"
         	 "���������򲻿��ٺ���ˣ�\n"NOR);
		if (me->query("marry"))
			write(HIY"ע�⣡��İ��½���˶��عѣ����ƹ������಻��Դ���\n���κβ����������ؾ�����\n"NOR);
   	input_to("check_password", 1, me, 1);
    return 1;
}

private void check_password(string passwd, object me, int forever)
{
    	object link_ob;
    	string old_pass;
    	string name;
    	link_ob = me->query_temp("link_ob");
    	old_pass = link_ob->query("password");
    	if( crypt(passwd, old_pass)!=old_pass )
    	{
        	write("�������\n");
        	return;
    	}

    	if (forever)
    	{
        	tell_object( me,WHT "
        	
        	����壬�������
             ��Ҷ�ۻ�ɢ����ѻ�ܸ�����
        ��˼���֪���գ���ʱ��ҹ��Ϊ�顣
        	
    �����ˣ�ϣ�������ܸ�������һ�������Ļ��䡣\n\n\n" NOR);
        	link_ob = me->query_temp("link_ob");
        	if( !link_ob ) return 0;

        	log_file("static/SUICIDE",
                	sprintf("%s commits a suicide on %s\n", geteuid(me), ctime(time())) );

        	seteuid(getuid());

//      name = me->query("id"); CALL-ID Bug�������Ǵ�link_ob������������
		name = link_ob->query("id");

        	if (me->query("combat_exp")>= 3000) 
        	{
        		LOGIN_D->cphirdir(DATA_DIR + "login/" + name[0..0] + "/" + name, "/suicide/login/"+name+time());
	        	LOGIN_D->cphirdir(DATA_DIR + "user/" + name[0..0] + "/" + name, "/suicide/user/"+name+time());
        	}
        	rmhirdir(DATA_DIR + "login/" + name[0..0] + "/" + name );
        	rmhirdir(DATA_DIR + "user/" + name[0..0] + "/" + name );

        	tell_room(environment(me), me->name() +
                  	"��ɱ�ˣ��Ժ�����Ҳ������������ˡ�\n", ({me}));
        	CHANNEL_D->do_sys_channel("info",me->name(1)+"("+me->query("id")+
                                  ")��ɱ�ˣ��Ժ�����Ҳ������������ˡ�");
        	destruct(me);
        	return 0;
    	}
}

int rmhirdir(string dirstr)
{
	string *dir;
	int i;
	dir = get_dir(dirstr+"/");
        for(i=0; i<sizeof(dir); i++) {
                if(file_size(dirstr+"/"+dir[i]) == -2 ) {
                                rmhirdir( dirstr +"/"+dir[i]);
                                rmdir(dirstr+"/"+dir[i]);
                                                }
                rm(dirstr+"/"+dir[i]);
        }
	rmdir(dirstr);
	return 1;
}

int help (object me)
{
        write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	suicide -f[0m
[0;1;37m����������������������������������������������������������������[0m   
 
�����Ϊĳ��ԭ���㲻�����, �����ѡ����ɱ��
��ɱ�ķ�ʽΪ:
 
suicide -f : ��Զ�ĳ�ȥ�������, ϵͳ��Ҫ����
             ����������ȷ����ݡ�
 
������ѽ�飬��ָ�������İ������졣
������ѡ�� :)

[0;1;37m����������������������������������������������������������������[0m   
 
HELP
);
        return 1;
}

