//TIE@FY3`
inherit NPC;
void create()
{
        set_name("������", ({ "luliu" }) );
        set("gender", "����" );
        set("age", 53);
        set("long", "
һ���������ˣ��뷢���Ѿ����ˣ�����ȴ����ͦ�ı�ֱ���۾������Ĺ�â
Զ�Ƚ��滹���ˡ�\n");
        
        set("combat_exp", 4000000);
        set("no_busy",6);
       
        set("chat_chance", 1);
        set("chat_msg", ({
		"��������������֮�����������ġ�\n",
                (: random_move :),
        }) );
	set_skill("throwing",100);
	set_skill("feidao",100);
	map_skill("throwing","feidao");
        setup();
        carry_object(__DIR__"obj/greencloth")->wear();
	carry_object(__DIR__"obj/7inch")->wield();
}


int heal_up()
{
	if(!query_temp("right_hand")) carry_object(__DIR__"obj/7inch")->wield();
	return ::heal_up() + 1;

}
