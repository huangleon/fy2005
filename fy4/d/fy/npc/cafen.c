// waiter.c

inherit NPC;
inherit F_VENDOR;
int tell_him();
void create()
{
	set_name("��Ӣ", ({ "hu ying","hu" }) );
	set("gender", "����" );
	set("title", "�ײĵ��ϰ�");
	set("age", 55);
	set("long","��λ���˵����ϲ�����ƣ�����\n");
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set("per",30);
	set("vendor_goods", ([
        	__DIR__"obj/zhiqian":100,
        	__DIR__"obj/zhihua":100,
        	"/obj/item/paper_seal":300,
	]) );
    	set("inquiry", ([
        	"coffin" : (: tell_him :),
        	"�ײ�" : (: tell_him:),
        ]));
	set_skill("unarmed",5);
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
message_vision("$N����$nһ�۵���ľ��û���������ˣ�̫�������ˡ�\n",this_object(),ob);
                        break;
                case 1:
message_vision("$N��$n�ʵ���˭���ˣ�\n",this_object(),ob);
                        break;
        }
}

int tell_him()
{
    object me;
    me =this_player();
	if (REWARD_D->riddle_check( me, "��̽����")==1
		|| REWARD_D->riddle_check( me, "��̽����")==2) {    
      	tell_object(me,"��Ӣ�����ҳ���˵��������һ���������ˣ����������û��ľ���ˣ�\n");
    	tell_object(me,"��Ӣ��:��ȥ��Щľ������Ҳ��������һ��.\n");
        REWARD_D->riddle_set( me,"��̽����", 2);
        return 1;
    } 
    return 0;
}

int accept_object(object who, object ob)
{
    if( (string) ob->query("name") == "÷������" 
    	&& REWARD_D->riddle_check( who,"��̽����")==2) {
		if(ob->query_amount()<20) {
			tell_object(who,"��Ӣ�����ⲻ�����������ùײĵģ�\n");
			return 0;
		} else {
			tell_object(who, "��Ӣָ��ǽ�ǵĺ�ľ�ײĵ�������Ϊ�ǹײĵ�ʽ����Σ�\n");
			tell_object(who, "�㷢�ֺ�ľ�ײĵĸ�û�иǺã��ƺ������ƿ��������裩��\n");
			REWARD_D->riddle_set( who,"��̽����", 3);        			}
        	return 1;
	}	
    return 0;
}

void reset()
{
	set("vendor_goods", ([
        __DIR__"obj/zhiqian":100,
        __DIR__"obj/zhihua":100,
        "/obj/item/paper_seal":300,
	]) );
}
