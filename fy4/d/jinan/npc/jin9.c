// garrison.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�����", ({ "jin" }) );
        set("long",
                "����䱾���������µ�һ�񲶣��߹��У���ʵΪ���������󰸵��廨�����
½С�������������Ž�����֮�ڷ����ֱ���Ѻ�ڼ��������С�\n");

        set("attitude", "heroism");
        set("title", "�廨���");
		set("no_heal",1);
        set("cor", 26);
        set("cps", 25);
        set("kee", 2000);
        set("max_kee", 2000);
        set("eff_kee", 500);
		set("no_arrest",1);
        set("combat_exp", 1000000+random(4000000));

        set_skill("unarmed", 70+random(500));
        set_skill("dagger", 300);
        set_skill("parry", 70+random(500));
        set_skill("dodge", 70+random(500));
        set_skill("move", 100+random(500));

        set_temp("apply/attack", 200);
        set_temp("apply/dodge", 200);
		set_temp("apply/parry", 200);
        set_temp("apply/damage", 100+random(200));
        set_temp("apply/armor", 10);
        set_temp("apply/move", 10);
        set("chat_chance", 1);
        set("chat_msg", ({
"����䳤̾һ����Ȼ������ʵ���ǵ͹���½С�����ˡ�����\n",
        }) );

        setup();
    	carry_object(__DIR__"obj/xiuhuazhen")->wield();
    	carry_object(__DIR__"obj/bloodcloth")->wear();

}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
		say( "�����������̧��ͷ������һ�ۣ��϶����������ţ����ҡ������ȣ��������壩������ �ҡ�����\n");
}

void init()
{
	::init();
	if( interactive(this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, this_player());
	}
	add_action("do_rescue", "rescue");
}


int do_rescue(){
	object ob,money;
	if (!objectp(ob=this_player()->query_temp("weapon")))
		return notify_fail("���ñ�������û�취�ҿ�������\n");
	if (ob->query("skill_type")!="hammer")
		return notify_fail("������ֻ���ô��Ӳ����ҿ�������\n");
	if (sizeof(environment(this_object())->query("exits"))==0)
		return notify_fail("Ҫ���ˣ������ȿ����Űɣ�\n");
	if (this_player()->query("str")<21)
		return notify_fail("���þ�ȫ���������������ȴ��˿δ��\n");			
	
	message_vision("$N����"+ob->query("name")+"���þ�ȫ���Ѽ����ҿ���\n",this_player());
	message_vision("$N������ɢ���������Ц��������������½С��һ�������������ʵģ�\n",this_object());
	
	if (this_player()->query("marks/prison_break")
		|| this_player()->query("combat_exp")<1600000) {
		message_vision("$N���˻����䣬��Ц����Ӱ���ޡ�\n",this_object());
		} else {
		this_player()->set("marks/prison_break",1);
		message_vision("$N�����۾�ɨ��$nһ�ۣ�Ҳ�����������ң��⼸����Ʊ����������л��\n",this_object(),this_player());
		message_vision("$N���˻����䣬��Ц����Ӱ���ޡ�\n",this_object());
		money=new(THCASH_OB);
		money->set("illegal",1);
		money->move(this_player());
		money=new(THCASH_OB);
		money->set("illegal",1);
		money->move(this_player());
		money=new(THCASH_OB);
		money->set("illegal",1);
		money->move(this_player());
		}
	destruct(this_object());
	return 1;
}