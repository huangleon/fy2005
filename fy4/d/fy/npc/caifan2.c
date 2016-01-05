// annie 07.2003
// dancing_faery@hotmail.com

inherit NPC;
inherit F_VENDOR;

#include <ansi.h>

void create()
{
        set_name("���˵�", ({ "cai fan","fan" }) );
        set("gender", "����" );
        set("age", 40);
        set("long","һ����ɫ��ף������տ�������ˣ�ȴ���������ˡ�\n");
		set("combat_exp", 3400000);
        set("attitude", "friendly");
        set("rank_info/respect", "�϶���");
        set("chat_chance", 1);
        set("chat_msg", ({
                "���˵�Ц������˵�˷����˷��������������Ǽ�ʶ��ʶ�����Ĳ˷�����\n",
        }) );

        set("vendor_goods", ([
                __DIR__"obj/smallvege":11,
                __DIR__"obj/bigvege":22,
                __DIR__"obj/midvege":22,
                __DIR__"obj/tomato":10,
                __DIR__"obj/cucumber":10,

        ]) );
        setup();

		set_skill("dodge",200);
		set_skill("parry",200);
		set_skill("blade",200);
		set_skill("force",200);
		set_skill("moon-blade",120);
		set_skill("meng-steps",200);
		set_skill("wuzheng-force",200);
		set_skill("bat-blade",200);
		set_skill("demon-blade",200);
		set_skill("demon-steps",200);		
		set_skill("demon-force",200);
		set_skill("ittouryu",200);
		set_skill("lianxin-blade",200);
		set_skill("wind-blade",200);
		set_skill("qiusheng-blade",200);
		set_skill("shenji-blade",200);
		set_skill("shenji-steps",200);		
		set_skill("springrain-blade",200);
		set_skill("shortsong-blade",200);
		set_skill("chillblade",200);
		map_skill("blade","moon-blade");
        map_skill("dodge","moon-blade");
        map_skill("parry","moon-blade");

		carry_object("/obj/armor/cloth")->wear();
		carry_object("/obj/item/carver")->wield();
}

void init()
{
        ::init();
        add_action("do_vendor_list", "list");
}

void reset()
{
	// ��Ϊ��ɫ��ǿ����Ҫreset....��Ӧ������quest.
        set("vendor_goods", ([
                __DIR__"obj/smallvege":11,
                __DIR__"obj/bigvege":22,
                __DIR__"obj/midvege":22,
                __DIR__"obj/tomato":10,
                __DIR__"obj/cucumber":10,
        ]) );
}



int do_attack() {
	int i = random(10);	
	if (query_busy() > 1)
	{
		start_busy(1);
		return 1;
	}
	else
		stop_busy();
	if (!query_temp("weapon"))
        carry_object("/obj/item/carver")->wield();

	switch(i) {
		case 1: //
			ccommand("enable blade bat-blade");
			map_skill("force","wuzheng-force");
			map_skill("dodge","meng-steps");
			set("class","bat");
			ccommand("perform shiwanshenmo");
			break;
		case 2:	//
			ccommand("enable blade demon-blade");
			map_skill("dodge","demon-steps");
			map_skill("force","demon-force");
			set("class","demon");
			ccommand("perform tiandirenmo");
			break;
		case 3:
			ccommand("enable blade ittouryu");
			set("class","ninja");
			ccommand("perform gobankiri");
			break;
		case 4: // 
			ccommand("enable blade wind-blade");
			ccommand("perform leitingpili");
			break;
		case 5:
			ccommand("enable blade qiusheng-blade");
			set("class","huangshan");
			ccommand("perform jingsheng");
			break;
		case 6:
			ccommand("enable blade shenji-blade");
			ccommand("enable dodge shenji-steps");				
			set("class","shaolin");
			ccommand("perform jichulianhuan");
			break;
		case 7:
			ccommand("enable blade shortsong-blade");
			set("class","legend");
			ccommand("perform duangechangmeng");
			break;
		case 0:
			ccommand("enable blade springrain-blade");
			ccommand("perform dangshimingyue");
			break;
		case 8:
			ccommand("enable blade ittouryu");
			set("class","ninja");
			ccommand("perform hyakki");
			break;
		case 9:
			ccommand("enable blade chillblade");
			set("class","moon");
			delete("timer");
			ccommand("perform mingyue");
			break;
	}

	switch (random(3))
	{
	case 0:
	    message_vision(CYN"\n���˵�Ц������˵�˷����˷��������������Ǽ�ʶ��ʶ�����Ĳ˷�����\n"NOR,this_object());
		break;
	case 1:
	    message_vision(CYN"\n���˵�Ц�����˷�����ζ��Σ�\n"NOR,this_object());
		break;
	case 2:
	    message_vision(CYN"\n���˵�Ц���������˵����˷�����ɱ�˷�����ɱ���˷�����ɱ�����˷�����\n"NOR,this_object());
		break;
	}



}
void heart_beat()
{
	::heart_beat();
	if(is_fighting())
			do_attack();
}
