//TIE@FY3`
inherit NPC;
void create()
{
        set_name("���ӣ", ({ "hongying" }) );
        set("gender", "����" );
        set("age", 53);
        set("long", "
һ���������ˣ��뷢���Ѿ����ˣ�����ȴ����ͦ�ı�ֱ���۾������Ĺ�â
Զ�Ƚ��滹���ˡ�\n");
        
        set("combat_exp", 4000000);
        set("reward_npc", 1);
	set("difficulty", 5);
	set("no_busy",5);
	set("attitude","friendly");
        
        set("chat_chance", 1);
        set("chat_msg", ({
"���ӣ������ӣ����������֮����\n",
                (: random_move :),
        }) );
	
	set_skill("throwing",200);
	set_skill("feidao",60);
	map_skill("throwing","feidao");
        
        setup();
        carry_object(__DIR__"obj/redcloth")->wear();
	carry_object(__DIR__"obj/7inch")->wield();
}


int heal_up()
{
	if(!query_temp("right_hand")) 
		carry_object(__DIR__"obj/7inch")->wield();
	return ::heal_up() + 1;

}
