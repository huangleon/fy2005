// jiading.c

inherit NPC;
string kill_passenger(object who);
void create()
{
        set_name("���¼Ҷ�", ({ "guard" }) );
        set("gender", "����" );
        set("age", 38);
        set("str", 28);

        set("max_force", 100);
        set("force", 100);
        set("force_factor", 10);

        set("attitude", "aggressive");

        set("long",@LONG
����һλ���ɱ��ļҶ���ר�����̲�ȥ���ɱ������ˡ�
LONG);

        set("combat_exp", 5000);
        set("score", 50);

        set_skill("hammer", 60);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/8hammer")->wield();
}

void init()
{
	object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("checklooking");
                call_out("checklooking", 1, ob);
        }
}

void checklooking(object ob)
{

	 if (!ob || environment(ob)!=environment())
	 	return;
	 if ( random((int)ob->query("per")) < 5  )
	 {
		command("say վס�����ʲô�ġ�");
		command("say ��������ü���ۣ����������������������ʲô�ö�����");
                kill_ob(ob);
	 }	
}
