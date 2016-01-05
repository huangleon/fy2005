// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	object weapon;
	set_name("С��", ({ "jat" }) );
	set("class","shaolin");
	set("gender", "����" );
	set("age", 29);
	set("per", 36);
	set("int", 40);
	set("str", 24);
	set("score",-10000);
	set("title","ҩҽ������");
	set("nickname",CYN"�����Ե��"NOR);
	set("attitude", "friendly");
	set("chat_chance", 0);
	set("chat_msg", ({
	"С��˵�������ҩ����Ϊ������Ѱ��ʵ��ֻ������֮˵�����������Σ�ҽ��Ҳ���ް��ա�\n",
	"С��˵����������ؼ��������Լ�������ҩ���ʹ�˹��������\n",
	"С��˵��������㲻���߻���ħ������ȥѰҩ������һ��(try)��\n",
	"С��˵����������ҩ�����"HIR BLK"ѩ������"NOR"��"WHT"ǧ����¶"NOR"��"HIW"���ر���"NOR"��\n",
	}) );

	set("no_curse",1);
	set("no_arrest",1);

	set("skill_public",1);

	set_skill("herb",400);
	set_skill("zen",400);
	set_skill("chanting",400);
	set_skill("dream-herb",400);
	map_skill("herb","dream-herb");

	set("NO_KILL","С��˵���������ӷ����գ����ա�\n");

	setup();

	weapon=carry_object("/obj/armor/ring");
	weapon->set_name("ħ��", ({ "magic ring","ring" }) );
	weapon->wear();
	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name("�����", ({ "cloth" }) );
	weapon->wear();

}

void init()
{
	add_action("do_try","try");
}

int do_try()
{
	object me;
	object d1,d2,d3;
	me = this_player();
	d1 = present("ice",me);
	d2 = present("dew drop",me);
	d3 = present("kirin heart",me);
	if (!d1 || !d2 || !d3)
		return notify_fail("��û���ռ������������귨����������ֲ��ϡ�\n");
	if (!d1->query("real") || !d2->query("real") || !d3->query("real"))
		return notify_fail("��û���ռ������������귨����������ֲ��ϡ�\n");
	destruct(d1);
	destruct(d2);
	destruct(d3);
	message_vision(HIB"\n$N����ѩ�����ģ���ɫ��ת���ϣ�������ѩ���ﶳ����ҹһ�㡣\n"NOR,me,this_object());
	message_vision(HIW"\n$n�ɿ�ؽ����ر�������$N���ϣ�ȡ��һö���봩����������$Nü�ġ�\n\n"NOR,me,this_object());
	tell_object(me,HIW"��ֻ���溮���ģ�������Ȼӿ���࿹��\n");
	me->unconcious();
	message_vision(CYN"\n$n����$N��ι$N����ǧ����¶��������һ������ת���ȥ��\n\n"NOR,me,this_object());
	if (random(100) < 60)
	{
		me->add("max_force", 50); 
		me->add("Add_force/jat_herb",50);
	}
	else
	{
		me->add("max_force", -50); 
		me->add("Add_force/jat_herb",-50);
	}
	destruct(this_object());
	return 1;
}


/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/

/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
