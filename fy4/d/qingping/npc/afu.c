// XXDER
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("����" , ({ "afu", "a fu" }) );
	set("long", "һ�������ձ������ˣ�û��֪������ʲô����Ҷ�����������\n");
	set("attitude", "friendly");
	set("age", 58);
        set("gender", "����" );
	set("combat_exp", 50000);
	set_skill("dodge", 20+random(20));
	set_skill("unarmed",50+random(50));
	set("force_factor",50);
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 10, ob);
	}
}

void greeting(object ob)
{
   if( !ob || environment(ob) != environment() ) return;
   switch( random(3) ) {
      case 0:
         message_vision("$N���ص�˵��������֪��֪���⻨԰����ͨ����ס�ĵط�? ��\n",this_object(),ob);
         break;
      case 1:
         message_vision("$N̾�˿���˵��������Ůʲôʱ���������? �� \n", this_object(),ob);
         break;
      case 2:
         message_vision("$N����������������⻨԰��ʰƯ������Ůһ���������ġ��� \n", this_object(),ob);
         break;
   }
   return;
}
