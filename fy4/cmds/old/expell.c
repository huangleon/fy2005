// expell.c

#include <skill.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    object ob;
    string *skname;
    string msg;
    mapping skills;
    int i;

    if( !arg || !ob = present(arg, environment(me)) )
        return notify_fail("��Ҫ��˭���ʦ�ţ�\n");

    if( !ob->is_character() )
        return notify_fail("��Ҫ���˭����\n");

    if( !userp(ob) )
        return notify_fail("��ֻ�ܿ�����������ݵ����\n");

    if(!ob->is_apprentice_of(me) && 
       !(me->query("family/privs")==-1 &&
         (string)me->query("family/family_name")==
         (string)ob->query("family/family_name") &&
         (int)me->query("family/generation") >
         (int)ob->query("family/generation")))
        return notify_fail("����˲�����ĵ��ӡ�\n");
    
    message_vision("$N����$n˵�����ӽ���������Ҳ������"
                   + me->query("family/family_name") +
                   "�ĵ����ˣ����߰ɣ�\n", me, ob);
    
    msg=sprintf("%s(%s)��%s%s(%s)�������%s���ˣ�",
                ob->name(1),ob->query("id"),
                me->query("family/title"),
                me->name(1),me->query("id"),
                me->query("family/family_name"));
    CHANNEL_D->do_sys_channel("info", msg);

    ob->assign_title("��ͽ",1);
    ob->delete("family/master_id");
    ob->delete("family/master_name");
    
    skills = ob->query_skills();

    if( mapp(skills) )
    {
        skname = keys(skills);
        for(i=0; i<sizeof(skname); i++)
            skills[skname[i]] /= 2;
    }

    return 1;
}

int help(object me)
{
    write(@HELP
ָ���ʽ : expell <ĳ��>
 
���ָ��������㿪�����ɲŵĵ��ӣ��������ĵ������м��ܶ��ή��ԭ��
��һ�룬�����ۺ�����һ������㣬����һ�����������һ����������
���ء��Ĵ���������ڿ���һ������֮ǰ����������ǡ�
 
HELP
	);
    return 1;
}
