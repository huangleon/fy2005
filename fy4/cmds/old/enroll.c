// enroll.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, old_enr;
	mapping organization;
	int i;

	if( !arg ) return notify_fail("ָ���ʽ��enroll [cancel]|<����>\n");

	if( arg=="cancel" ) {
		old_enr = me->query_temp("pending/enroll");
		if( !objectp(old_enr) )
			return notify_fail("�����ڲ�û����¼�κ���Ϊ��Ա����˼��\n");
		write("��ı����ⲻ����" + old_enr->name() + "Ϊ��Ա�ˡ�\n");
		tell_object(old_enr, me->name() + "�ı����ⲻ������Ϊ��Ա�ˡ�\n");
		me->delete_temp("pending/enroll");
		return 1;
	}

	if( !(ob = present(arg, environment(me))) )
		return notify_fail("������˭����Ա��\n");

	if( ob==me ) return notify_fail("���Լ�Ϊ��Ա��������....����û���á�\n");

	if( ob->is_member_of(me) ) {
		message_vision("$N����$n��ͷ��˵���������ֵܣ���\n", me, ob);
		return 1;
	}

	if( !me->query("organization") )
		return notify_fail("�㲢������κ���֯��������ȼ���һ����֯�����Լ���һ���������ճ�Ա��\n");
        if( userp(me) && (int) me->query("organization/privs")!= -1 )
                return notify_fail("�����쵼������ļ��Ա��\n");
        if((string)me->query("organization/org_name") ==
           (string)ob->query("organization/org_name"))
        if((int)me->query("organization/generation") >=
           (int)ob->query("organization/generation"))
                return notify_fail(ob->name()+"�ı��ֲ�������ͣ�\n");
	// If the target is willing to join us already, we do it.
	if( (object)ob->query_temp("pending/join") == me ) {

		if( !living(ob) ) {
			message_vision(
				"$N������$nΪ��Ա��\n\n"
				"����������$n��Ȼû�а취�����֮��\n\n",
				me, ob);
			return 1;
		}
		if(mapp(ob->query("organization")) &&
                   (string)me->query("organization/org_name") !=
                   (string)ob->query("organization/org_name") )
                {
         
                        message_vision("$N��������ԭ������֯����Ͷ��$n����֯\n\n"
                "$N����������$n���������ؿ���һ����ͷ���е�������磡��\n\n",
                        ob, me);
                        if(ob->query("score") > 5000) ob->add("score", -5000);
			ob->add("betrayer", 1);
		} else
			message_vision(
				"$N������$nΪ��Ա��\n\n"
				"$n����������$N���������ؿ���һ����ͷ���е�������磡��\n",
				me, ob);

		me->enroll_member(ob);
		ob->delete_temp("pending/join");

		write("��ϲ��������һ����Ա��\n");
		organization = ob->query("organization");
		tell_object( ob, sprintf("��ϲ����Ϊ%s�ĵ�%s����Ա��\n", organization["org_name"],
			chinese_number(organization["generation"]) ));

		return 1;
	

	} else {

		old_enr = me->query_temp("pending/enroll");
		if( ob==old_enr )
			return notify_fail("������" + ob->name() + "Ϊ��Ա�����ǶԷ���û�д�Ӧ��\n");
		else if( objectp(old_enr) ) {
			write("��ı����ⲻ����" + old_enr->name() + "Ϊ��Ա�ˡ�\n");
			tell_object(old_enr, me->name() + "�ı����ⲻ������Ϊ��Ա�ˡ�\n");
		}

		me->set_temp("pending/enroll", ob );
		message_vision("\n$N��Ҫ��$nΪ��Ա��\n", me, ob);
		tell_object(ob, YEL "�����Ը�����" + me->name() + "����֯���� join ָ�\n" NOR);
		return 1;
	}
}
/*

int help(object me)
{
        write(@HELP
ָ���ʽ : enroll [cancel]|<����>
 
���ָ����������ĳ��Ϊ��Ա, ����Է�Ҳ��ӦҪ����Ϊʦ�Ļ�.
 
HELP
        );
        return 1;
}
*/