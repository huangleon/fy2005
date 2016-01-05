// chpasswd.c
// add by Karry@FY3

#include <login.h>;
inherit F_CLEAN_UP;

void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
        object ob,link_ob;
        string id,password;
        if(!arg||sscanf(arg,"%s %s",id,password)!=2)
                return notify_fail("�÷�:chpasswd ID ������\n�����ô�ָ�\n");
        ob=find_player(id);
        if(!ob)
        {
        ob = new(LOGIN_OB);
        ob->set("id",id);
    	
        if( !ob->restore() )
                return notify_fail("û�������ҡ�\n");
 
        else
                {                                    
           ob->set("password",crypt(password,0));
           tell_object(me, "���" + ob->query("id") + "("+ob->query("name")
                     + ")�������Ѿ�����Ϊ��"+password+"��\n");
 
                    log_file( "changepw", sprintf("%s %s(%s)�޸���%s(%s)������\n",
                ctime(time()), me->query("name"), me->query("id"),
                ob->query("name"), ob->query("id")));
           ob->save();
           destruct(ob);
           return 1;
                }
        }
        link_ob=ob->query_temp("link_ob");
        if(link_ob)
        {
                link_ob->set("password",crypt(password,0));
                link_ob->save();
                tell_object(me, "���" + ob->query("id") + "("+ob->query("name")
                        + ")�������Ѿ�����Ϊ��"+password+"��\n");
                return 1;
        }
        else
                return notify_fail("�����޷������޸ġ�\n");
        return 1;
}


int help(object me)
{
        write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	chpasswd ID ������[0m
[0;1;37m����������������������������������������������������������������[0m   

���ָ������޸���ҵ����룬�����ʹ�á�

[0;1;37m����������������������������������������������������������������[0m 
HELP
    );
    return 1;
}
