// mind_beast.c

inherit NPC;

void create()
{
	set_name("ѩ����֬��", ({ "red horse", "horse" }) );
	set("race", "����");
	set("gender", "����");
	set("age", 3);
	set("long", "����һֻ�����׳��һ�˶�ߵ�ǧ����\n");
	
	set("attitude", "peaceful");
	
        set("chat_chance", 1);
        set("chat_msg", ({
		"ѩ����֬���ԡ������ԣ���˻���˼���\n",
        }) );
	set("combat_exp", 20000);
	set_temp("apply/attack", 60);
	set_temp("apply/armor", 40);
	set_temp("apply/dodge",40);
	setup();
	carry_object(__DIR__"obj/maan")->wear();
}
