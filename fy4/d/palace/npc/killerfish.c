inherit NPC;

void create()
{
        set_name("ʳ����", ({ "killer fish","fish" }) );
        set("race", "����");
        set("age", 4);

        set("long", "һ����¶�׹��ʳ���㡣\n");
        set("attitude", "aggressive");
        set_skill("dodge", 100);
	set_skill("move",300);
        set("combat_exp", 9000);
	set("bellicosity", 300 );
	add_temp("apply/damage",10+random(10));
        setup();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                kill_ob(ob);
	add_action("do_get","get");
        }
}

int do_get(string arg)
{
	string what, where;
	if(!arg) return 0;
	if(sscanf(arg,"%s from %s",what, where) !=2) return 0;
	if((what== "all" || what== "woodcase") && (where=="watergrass" || where=="ˮ��"))
	{
	message_vision("$N�ݺݵ���$nһ�ۣ�һ����$nҧ��������\n",this_object(),this_player());
	this_object()->kill_ob(this_player());
	this_player()->start_busy(2);
	return 1;
	}
}