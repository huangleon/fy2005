inherit NPC;
void create()
{
        set_name( "����", ({ "cuiliu","girl" }) );
	set("gender", "Ů��" );
	set("age", 20);
	set("long","����¥�Ĺ����Ȼû�н���Ů����ôС�����磬Ҳ���з��顣\n");
                
	
        set("chat_chance", 1);
        set("chat_msg", ({
                "�������������������˸����ۣ�һת��¶�����ѩ�׵Ĵ��ȡ�\n"
        }) );

	set("attitude", "peaceful");
	set("combat_exp", 500000);
        
        set_skill("unarmed", 100);
        set_skill("nine-moon-claw", 90);
        set_skill("nine-moon-steps",150);
        set_skill("parry",100);
        set_skill("dodge",100);
        map_skill("unarmed", "nine-moon-claw");
        map_skill("dodge","nine-moon-steps");
	setup();
	carry_object(__DIR__"obj/skirt",([	"name": "��ȹ��",
    					"long": "һ��Ư���Ļ�ȹ�ӡ�\n",
    					 ]))->wear();    
}
