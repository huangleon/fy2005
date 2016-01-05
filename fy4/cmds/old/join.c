// join.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    object ob, old_join;
    mapping organization, skills;
    int i;
    string *skname;

    if( !arg ) return notify_fail("ָ���ʽ��join [cancel]|<����>\n");

    if( arg=="cancel" ) {
        old_join = me->query_temp("pending/join");
        if( !objectp(old_join) )
            return notify_fail("�����ڲ�û�м����κ���֯����˼��\n");
        write("��ı����ⲻ���" + old_join->name() + "����֯�ˡ�\n");
        tell_object(old_join, me->name() + "�ı����ⲻ����������֯�ˡ�\n");
        me->delete_temp("pending/join");
        return 1;
    }

    if( !(ob = present(arg, environment(me)))
        || !ob->is_character() )
        return notify_fail("�������˭����֯��\n");

    if( mapp(me->query("organization")))
        if(me->query("organization/privs")==1)
            return notify_fail("��������һ��֮֯ͷ�������ټ�������֯�ˡ�\n");
        else if(me->query("organization/privs")==-1)
            return notify_fail("����һ��֮֯ͷ�������ټ�������֯�ˡ�\n");
    
    if( !living(ob) )
        return notify_fail("������Ȱ�" + ob->name() + "Ū�ѡ�\n");

    if( ob==me ) return notify_fail("�Լ������Լ����й���....����û���á�\n");

    if( me->is_member_of(ob) ) {
        message_vision("$N������������$n�����밲���е�������磡��\n", me, ob);
		if (!userp(ob)) ob->org_rerank(me);
        return 1;
    }

    if( !mapp( ob->query("organization") ) )
        return notify_fail(ob->name() +
                           "�Ȳ�����κ���֯��Ҳû�п����κ���֯�����ܼ��롣\n");
    if( userp(ob) && (int) ob->query("organization/privs") != -1 )
        return notify_fail("������֯���䲻�����ճ�Ա��\n");
    if((string)me->query("organization/org_name") ==
       (string)ob->query("organization/org_name"))
        if((int)me->query("organization/generation") <=
           (int)ob->query("organization/generation"))
            return notify_fail(ob->name()+"�ı��ֲ�������ߣ�\n");
    // If the target is willing to recruit us already, we do it.
    if( (object)ob->query_temp("pending/enroll") == me )
    {
        if( (string)me->query("organization/org_name") !=
            (string)ob->query("organization/org_name"))
        {
            message_vision("$N��������ԭ������֯����Ͷ��$n����֯\n\n"
                "$N����������$n���������ؿ���һ����ͷ���е�������磡��\n\n",
                me, ob);
            if(me->query("score") > 5000) me->add("score", -5000);
            me->add("betrayer", 1);
        }
        else message_vision("$N��������$n��֯��\n\n"
                "$N����������$n���������ؿ���һ����ͷ���е�������磡��\n\n",
                me, ob);

        ob->enroll_member(me);
        ob->delete_temp("pending/enroll");

        tell_object(ob, "��ϲ��������һ����Ա��\n");
        organization = me->query("organization");
        printf("��ϲ����Ϊ%s�ĵ�%s����Ա��\n", me->query("organization/org_name"),
               chinese_number( me->query("organization/generation")));

        return 1;
	
    } else {
        
        old_join = me->query_temp("pending/join");
        if( ob==old_join )
            return notify_fail("�������" + ob->name() +
                               "����֯�����ǶԷ���û�д�Ӧ��\n");
        else if( objectp(old_join) ) {
            write("��ı����ⲻ�����" + old_join->name() + "����֯�ˡ�\n");
            tell_object(old_join, me->name() + "�ı����ⲻ����������֯�ˡ�\n");
        }

        message_vision("$N��Ҫ����$n����֯��\n", me, ob);
        me->set_temp("pending/join", ob );
        if( userp(ob) ) {
            tell_object(ob, YEL "�����Ը����" + me->name() +
                        "Ϊ��Ա���� enroll ָ�\n" NOR);
        } else 
            ob->attempt_join(me);
	
        return 1;
    }
}

/*
int help(object me)
{
    write(@HELP
ָ���ʽ : join [cancel]|<����>
 
���ָ���������ĳ��Ϊʦ������Է�Ҳ��ӦҪ����Ϊͽ�Ļ����ͻ�������
��ʦ֮�񣬷���Ҫ�ȵ��Է��� recruit ָ������Ϊ���Ӳ�����ʽ��ʦ��

��ע�����Ѿ�����ʦ�����ֱ���ʦ��Ͷ��������£����м��ܿ��ܻ���룬����
���ۻή���㡣

��������ʦ��ʹ�����ָ�������ʦ���밲����Ҫ��ʦ�������
���ʵĳƺš�
 
��ο����ָ�� expell��recruit
HELP
        );
    return 1;
}
*/