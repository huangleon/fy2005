#include <ansi.h>
inherit NPC;
int tell_test();
void create()
{
        set_name("���", ({ "biao ge","biaoge" }) );
        set("gender", "����");
        set("class", "ghost");
        create_family("����ɽׯ", 3, "����");
        set("combat_exp", 600000);
        set("long",
		"�������⻬���׾��������Ǹ��հ��˿ǵļ�����\n"
	);
        set("inquiry", ([
                "��" : (: tell_test :),
                "mission" :(: tell_test :),
                "һ����": (: tell_test :),
                "shi":	(: tell_test :),
                "thing":	(: tell_test :),	
        ]) );
	set("no_arrest",1);
        set_skill("move", 150);
        set_skill("dodge", 150);
        set_skill("sword", 150);
        set_skill("three-sword", 100);
        set_skill("five-steps", 100);
        set_skill("parry",100);
        map_skill("parry","three-sword");
	map_skill("dodge", "five-steps");
	map_skill("move", "five-steps");
	map_skill("sword", "three-sword");
        setup();
	carry_object(__DIR__"obj/letter");
	carry_object(__DIR__"obj/letter");
	carry_object(__DIR__"obj/cloth2")->wear();
	carry_object(__DIR__"obj/sword3")->wield();
}

void init()
{
        ::init();
	if(interactive(this_player()) && !is_fighting()) {
		call_out("greeting", 1, this_player());
	}
}

int tell_test()
{
	object		me;

	me = this_player();	
	if(me->query_temp("marks/test")) {
		me->set_temp("marks/test", 0);
		tell_object(me, YEL "\n���˵�����¹��Ʒɣ��˰�ɽ���͵ĵ��ӣ���ʦ����������ɽׯ�Եס�"NOR);
		tell_object(me, YEL "\n����������һ���ж࣬������֪�ϵ����ӵ�����Ŀ��"NOR);
		tell_object(me, YEL "\n���Ѱ���һ�����������Ŷ�������������һֱû�л����ͳ�ȥ��"NOR);
		tell_object(me, YEL "\n��ϣ�����ܰ�����غ��͵��䵱����ʯ������С�(answer yes/no?)\n"NOR);
		me->set_temp("marks/�غ�", 1);
		add_action("do_accept", "answer");
		return 1;
	}
	return 0;
}

int greeting(object me)
{
	object		groom;

	if( (string)me->query("family/family_name")=="����ɽׯ" ) {
		message_vision(HIY "\n$N��$n�ȵ�����ĵ��Ӳ�С���������ϵ����ӵ�Ů�ˣ�\n"NOR, this_object(), me);
		message_vision(HIR "\n�������������ɣ�\n"NOR, this_object(), me);
	}
	else {
		message_vision(HIY "\n$N��$n�ȵ�����ĵ��Ӳ�С���������ϵ����ӵ�Ů�ˣ�\n"NOR, this_object(), me);
		message_vision(HIR "\n�����������һ���£����������������ɣ�\n"NOR, this_object(), me);
		me->set_temp("marks/test", 1);
	}
	return 1;
}

int do_accept(string arg)
{

	object 		me, nroom, letter;
	me = this_player();


	if(!arg || (arg != "yes" && arg != "no")) {
		tell_object(me,"answer yes/no\n");
		return 1;
	}
	if(!me->query_temp("marks/�غ�")) {
		tell_object(me,"answer yes/no\n");
		return 1;
	}
	me->delete_temp("marks/�غ�");

	if(arg == "yes") {
		letter = present("letter", this_object());
		if(!objectp(letter)) letter=new(__DIR__"obj/letter");
		tell_object(me, CYN"\n���Ʒ�Ц����̫���ˣ������غ������պá�\n"NOR);
		if (!letter->move(me))	letter->move(environment(me));
//			tell_object(me, HIY "\n���Ʒ�Ц����̫���ˣ��غ�������һ�����صĵط����´μ������ٸ��㡣\n"NOR);
		tell_object(me, CYN "\n�����������ȥ��\n"NOR);
		message_vision(HIR "\n����������ϰ���һ�£�$n�Ľ����ѿ���һ���󶴣�\n$n�����һ����������ȥ��\n"NOR, this_object(), me);
		me->set_temp("marks/���Ʒ�", 1);
		nroom = find_object(AREA_WUDANG"road1");
		if(!objectp(nroom)) nroom=load_object(AREA_WUDANG"road1");
		me->move(nroom);
		message_vision(HIR "\n$N��ɽ���ϵ�һ��С������������\n"NOR, me);
	}
	else {
		tell_object(me, CYN "\n���Ʒ�Ц�������������㣬�����㲻�Ǽ�ϸ��\n"NOR);
		tell_object(me, CYN "\n����������ȥ���ϵ����ӣ���������ã������������ʦѧ���֡�\n"NOR);
		me->set_temp("marks/����ɽׯ", 1);
		message_vision(HIR "\n����������ϰ���һ�£�$n�Ľ����ѿ���һ���󶴣�\n$n�����һ����������ȥ��\n"NOR, this_object(), me);
		nroom = find_object(AREA_WUDANG"house3");
		if(!objectp(nroom)) nroom=load_object(AREA_GHOST"house3");
		me->move(nroom);
		message_vision(HIR "\n$N����������˳�����\n"NOR, me);
	}
	return 1;
}
