// annie 07.2003
// dancing_faery@hotmail.com

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>

int leave();

void create()
{
        set_name("���ľ", ({ "zhen baimu","zhen" }) );
		// Useless Item'
        set("gender", "����" );
        set("age", 41);
        set("title", CYN"�绻����"NOR);
        set("long","��λ�ϰ���ǽ����ϴ�������ġ����չ������ľ��������\n����֮����������߼���������ЩС������Ϊ����\n��˵���ϰ嵱����"YEL"α������"NOR"��Ҳ����һ�֣�������˱��ٸ�����\nΧ�ˣ��������ϴ�ֲ��ɡ�\n");
        set("combat_exp", 900000);
        set("attitude", "friendly");
        set("per",30);
        set("vendor_goods", ([  
                __DIR__"obj/sp_pic"           	: 40,
                __DIR__"obj/sp_bottle"          : 40,
                __DIR__"obj/sp_clock"           : 40,
                __DIR__"obj/sp_carpet"		: 40,
                BOOKS"yuputuan":		50,
                BOOKS"jinpingmei":		50,
        ]) );
        set_skill("unarmed",150);
        set_skill("dodge",150);
        set_skill("parry",150);
		set_skill("lingxi-zhi",100);
		set("forger",1);
		map_skill("unarmed","lingxi-zhi");
		// ��һ����lx-zh��quest? *snicker

			set("inquiry",([
        		"α������": (: leave :),
    		]) );



        setup();
        carry_object(__DIR__"obj/fycloth")->wear();
}

int leave()
{
	object me,obj,*o;
	int i;
	string msg;
	me=this_player();

	o = all_inventory(me);
	for (i=0; i<sizeof(o); i++)
	{
		if (crypt(o[i]->query_weight()+"","Bj7mJPd4q6Pbk") != "Bj7mJPd4q6Pbk" 
			|| me->query_temp("annie/fy_zhen"))	continue;
		if (!query_temp("showed_miling"))	continue;		
		ccommand("hmm");
		ccommand("say ���Ǵ�������ұ��زپ�ҵһ�ء�");
		ccommand("emote ��˼�������ڵĹٶ���˭�ˡ�������");
		ccommand("emote ��"+me->name()+"����ȡ��һ�ת���ߵ�һ�ԡ�\nƬ��֮��");
		ccommand("emote ���Ƕ���С�����������"+me->name()+"�����˵�ͷ�����мǣ��мǣ����������á�");
		o[i]->add("re"+"al",1);
		me->set_temp("annie/fy_zhen",1);
		delete_temp("showed_miling");
		return 1;
	}

	ccommand("hehe");
	ccommand("say �����˵Ц��С�϶����������Ѿ�ʮ��������");
	ccommand("say �͹ٻ��ǿ���С�϶��Ļ�Ʒ�ɣ�������ȫ���������⡣");
	return 1;
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
		
		// ż��֪�����ֵط��ϰ�������ߺ��˵>"<

        return;
}

void reset()
{
        set("vendor_goods", ([
                __DIR__"obj/sp_pic"           : 40,
                __DIR__"obj/sp_bottle"           : 40,
                __DIR__"obj/sp_clock"           : 40,
                __DIR__"obj/sp_carpet"		  : 40,
                BOOKS"yuputuan":		50,
                BOOKS"jinpingmei":		50,
        ]) );
}

