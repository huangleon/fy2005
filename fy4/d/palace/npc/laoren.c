inherit NPC;

void create()
{
        set_name("�ձ�����", ({ "laozhe" }) );
        set("gender", "����" );
        set("age", 68);

        set("long","����һλ�þ���˪���ձ����ˡ�\n");
	set("bellicosity",1000000);
        set("combat_exp", 200000);
        
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("flying-dragon", 100);
        set_skill("zuixian-steps", 100);
	
        map_skill("unarmed", "flying-dragon");
        map_skill("dodge", "zuixian-steps");

	setup();
	carry_object("/obj/armor/cloth")->wear();
}

void init()
{
        object me;
        me = this_player();
        if( interactive(me))
                if (me->query("class") && me->query("class") != "yinshi")
                kill_ob(me);

}

