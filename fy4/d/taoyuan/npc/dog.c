inherit NPC;

void create()
{
        set_name("����", ({ "yellow dog", "dog", "����" }) );
        set("race", "Ұ��");
        set("age", 5);
        set("long", 
	"һ����������������ĺù���������������������㣬��ϲ������������ͷ��\n"
	);
        set("max_kee", 150);
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite" }) );

	set("combat_exp", 5000);
        set_skill("dodge", 100);

        setup();
}
void init()
{
   object ob;
	
   ::init();
   if( interactive(ob = this_player()) && !is_fighting() ) {
      remove_call_out("greeting");
      call_out("greeting", 1, ob);
   }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
message_vision("$N����$n�������˵�ҡҡβ�ͣ�����������$n��������ᡣ\n",this_object(),ob);
                        break;
                case 1:
message_vision("$N����$n�����ؽ��˼�����\n",this_object(),ob);
                        break;
                case 2:
message_vision("$N����$nһ�ۣ�������������¡�\n",this_object(),ob);
                        break;
        }
}

