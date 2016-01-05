
inherit SMART_NPC;

void create()
{
	set_name("���", ({ "huo fo", "fo" }) );
	set("gender", "����" );
	set("age", 109);
	set("int", 30);
	set("long","�����𣬵���ԭ�����Σ�\n"	);
	set("class","lama");
        set("combat_exp", 1000000);
        set("score", 90000);
        set("reward_npc", 1);
        set("difficulty", 5);
        
        set_skill("unarmed", 150);
	set_skill("move", 100);
        set_skill("staff", 150);
        set_skill("force", 150);
        set_skill("parry", 150);
        set_skill("literate", 150);
	set_skill("iron-cloth", 150);
	set_skill("magic", 150);
	set_skill("perception", 100);
	set_skill("bloodystrike", 150);
	set_skill("cloudstaff", 150);
	set_skill("bolomiduo", 150);
	set_skill("buddhism", 150);
	set_skill("essencemagic", 150);
        set_skill("jin-gang", 150);
	set_skill("kwan-yin-spells",150);
	set_skill("spells",150);
	
	map_skill("spells","kwan-yin-spells");
	map_skill("unarmed", "bloodystrike");
        map_skill("force", "bolomiduo");
        map_skill("literate", "buddhism");
        map_skill("iron-cloth", "jin-gang");
        map_skill("magic", "essencemagic");

		set("perform_busy_u", "lama/unarmed/bloodystrike/fofawubian");
	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(60) :),
        }) );

	setup();
        carry_object("obj/armor/cloth",([	"name": "������",
    						"long": "һ�������ۡ�\n",
    						 ]))->wear();  
}

int accept_object(object who, object ob)
{
        if( ob->value() >= 1000000)
        {
	message_vision("$N��$n˵������лʩ����\n",this_object(),who);
                return 1;
        }
        return 0;
}

