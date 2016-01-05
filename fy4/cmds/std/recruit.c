// recruit.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, old_rec;
	mapping family;
	int i, score_cost;

	if( !arg ) return notify_fail("ָ���ʽ��recruit [cancel]|<����>\n");

	if( arg=="cancel" ) {
		old_rec = me->query_temp("pending/recruit");
		if( !objectp(old_rec) )
			return notify_fail("�����ڲ�û����¼�κ���Ϊ���ӵ���˼��\n");
		write("��ı����ⲻ����" + old_rec->name() + "Ϊ�����ˡ�\n");
		tell_object(old_rec, me->name() + "�ı����ⲻ������Ϊ�����ˡ�\n");
		me->delete_temp("pending/recruit");
		return 1;
	}

	if( !(ob = present(arg, environment(me))) )
		return notify_fail("������˭�����ӣ�\n");

	if( ob==me ) return notify_fail("���Լ�Ϊ���ӣ�������....����û���á�\n");

	if( ob->is_apprentice_of(me) ) {
		message_vision("$N����$n��ͷ��˵��������ͽ������\n", me, ob);
		return 1;
	}

	if( !me->query("family") )
		return notify_fail("�㲢������κ����ɣ�������ȼ���һ�����ɣ����Լ���һ��������ͽ��\n");
        if( userp(me) && (int) me->query("family/privs")!= -1 )
                return notify_fail("���������˲�����ͽ��\n");
        if((string)me->query("family/family_name") ==
           (string)ob->query("family/family_name"))
        if((int)me->query("family/generation") >=
           (int)ob->query("family/generation"))
                return notify_fail(ob->name()+"�ı��ֲ�������ͣ�\n");
                
	// If the target is willing to apprentice us already, we do it.
	if( (object)ob->query_temp("pending/apprentice") == me ) {

		if( !living(ob) ) {
			message_vision(
				"$N������$nΪ���ӡ�\n\n"
				"����������$n��Ȼû�а취�а�ʦ֮��\n\n",
				me, ob);
			return 1;
		}
		if(mapp(ob->query("family")) &&
                   (string)me->query("family/family_name") !=
                   (string)ob->query("family/family_name") &&
                   (string)ob->query("family/title") !="��ͽ")
        {
            message_vision(
                "$N��������ʦ�ţ���Ͷ��$n���£���\n\n"
                "$N����������$n���������ؿ����ĸ���ͷ���е�����ʦ������\n\n",
                ob, me);
            score_cost = me->query("score_cost") ? me->query("score_cost") : 1000;
			if (!ob->query("family")) score_cost = 0;
            if(ob->query("score") > score_cost) 
               	ob->add("score", -score_cost);
            else 
              	ob->set("score",0);
			ob->add("betrayer", 1);
		} else
			message_vision(
				"$N������$nΪ���ӡ�\n\n"
				"$n����������$N���������ؿ����ĸ���ͷ���е�����ʦ������\n",
				me, ob);

		me->recruit_apprentice(ob);
		ob->delete_temp("pending/apprentice");
		ob->delete_temp("marks/apprentice_others");
		write("��ϲ��������һ�����ӣ�\n");
		family = ob->query("family");
		tell_object( ob, sprintf("��ϲ����Ϊ%s�ĵ�%s�����ӡ�\n", family["family_name"],
				chinese_number(family["generation"]) ));
		return 1;
		
	} else {

		old_rec = me->query_temp("pending/recruit");
		if( ob==old_rec )
			return notify_fail("������" + ob->name() + "Ϊ���ӣ����ǶԷ���û�д�Ӧ��\n");
		else if( objectp(old_rec) ) {
			write("��ı����ⲻ����" + old_rec->name() + "Ϊ�����ˡ�\n");
			tell_object(old_rec, me->name() + "�ı����ⲻ������Ϊ�����ˡ�\n");
		}

		me->set_temp("pending/recruit", ob );
		message_vision("\n$N��Ҫ��$nΪ���ӡ�\n", me, ob);
		tell_object(ob, YEL "�����Ը���" + me->name() + "Ϊʦ������ apprentice ָ�\n" NOR);
		return 1;
	}
}


int help(object me)
{
        write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	recruit [cancel]|<����>[0m
[0;1;37m����������������������������������������������������������������[0m   
 
���ָ����������ĳ��Ϊ����, ����Է�Ҳ��ӦҪ����Ϊʦ�Ļ�.

[0;1;37m����������������������������������������������������������������[0m   
 
HELP
        );
        return 1;
}
