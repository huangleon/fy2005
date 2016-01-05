inherit NPC;

void create()
{
        set_name("�ϵ�ʿ", ({ "old taoist" }) );
        set("gender", "����");
        set("age", 72);
        set("long",
"���Ǹ����ϵĵ�ʿ���۹�ȴ��������\n"
);
        set("combat_exp", 400000);
        set("score", 200);

        set("class", "taoist");
        set("inquiry", ([
                "�����ķ�": 
"�����ķ�����éɽ��Ϊ�Կ�аħ����������ڹ��ķ���\n",
        ]) );
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "drainerbolt" :),
        }) );

        create_family("���幬", 5, "����");

        set_skill("move", 120);
        set_skill("force", 200);
        set_skill("spells", 100);
        set_skill("unarmed", 120);
        set_skill("sword", 120);
        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("gouyee", 120);
        set_skill("notracesnow",160);
        set_skill("taoism", 120);
        set_skill("necromancy", 100);            
	set_skill("snowshade-sword",120);

	map_skill("force", "gouyee");
	map_skill("unarmed","tenderzhi");
	map_skill("dodge","notracesnow");
	map_skill("spells", "necromancy");
	map_skill("parry", "snowshade-sword");
	map_skill("sword", "snowshade-sword");
	

        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);

        setup();

        add_money("coin", 30);
	carry_object(__DIR__"obj/o_cloth")->wear();
	carry_object(__DIR__"obj/r_sword")->wield();
}

int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="���幬" ) {
                command("nod");
                command("say ���аɡ�");
                return 1;
        }
        command("say ���幬���ͱ��ɵ��˹��С�");
        return 0;
}
 
