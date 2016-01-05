// tea_waiter.c

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>

int quest();

void create()
{
        set_name("½��", ({ "lu yu","lu","waiter" }) );
        set("gender", "����" );
        set("title","������");
        set("age", 40);
        set("long", "½����æ���к�����, һ�����Ų��, һ������Ĩ����\n");
		set("NO_KILL","����̫��Ҫ��ɱ��˭�����ݲ裿\n");
		set("combat_exp", 3000);
        set("attitude", "friendly");
        set("rank_info/respect", "������");
        set("vendor_goods", ([
//                "/obj/medicine/party/pill_qingtuan": 50,
                "/obj/food_item/luteapot": 50,
                "/obj/food_item/dumpling": 50,
                "/obj/food_item/chicken_leg": 50,
// "/obj/wiz_toy/taskstone1": 150,
                __DIR__"obj/longjin":50,
        ]) );
        set("inquiry", ([
        	"ˮ��":		(:quest:),
        	"job":		(:quest:),
        	"����":		(:quest:),
        ]));	
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
        switch( random(3) ) {
                case 0:
                        say( "½��Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�������ȱ��裬ЪЪ�Ȱɡ�\n");
                        break;
                case 1:
                        say( "½����ë��Ĩ��Ĩ���ŵ�һ�����ӣ�˵������λ" + RANK_D->query_respect(ob)
                                + "����������\n");
                        break;
                case 2:
                        say( "½��˵������λ" + RANK_D->query_respect(ob)
                                + "�����������Ųɵ��²�Ҷ����! ���㰡!...\n");
                        break;
        }
}

int quest(){

	object me = this_player();
	object teapot;
	string pos, area, water;
	// 0-22 easy, 23-30 run more, 31-36 run even more
	
	string *source = ({ "����ɽ:�����ˮ",
						"����ɽ:��̶��ˮ",
						"ǧ��ɽ:ɽȪˮ",
						"�䵱ɽ:��Ȫˮ",
						"��÷ɽׯ:С��ˮ",
						"��÷ɽׯ:��ˮ",
						"��ѩɽׯ:÷��̶ˮ",
						"��Դ:��̶ˮ",
						"�ر�ɳĮ:�Ŷ�̲ˮ",
						"��ɽ:��Ȫˮ",
						"�½�:���ݱ���ˮ",
						"�½�:�峺��Ϫˮ",
						"������:����Ϫˮ",
						"������:��Ȫˮ",
						"̫ƽ��:����ˮ",
						"������:С����ˮ",
						"��ɽ:����Ϫˮ",
						"��ɽ:������ˮ",
						"����:��ͻȪˮ",
						"����:������ˮ",
						"����:������ˮ",
						"��ɽ:ӥ�ˮ",
						"����ɽׯ:ɽ��ˮ",		// �ɼ�ð
//						"����ɽׯ:��Ȫˮ",	  too hard
						
						"��ϼɽ:ʯ��",
//						"��˼ɽ:���Ϻ�Ȫ",
//						"��˼ɽ:�����¶",
						"��˼ɽ:��Ϫˮ",
						"��ɽ:����Ȫˮ",
						"���Ƶ�:����Ȫˮ",
						"���Ƶ�:Ǳ��Ȫˮ",
						"��ɽ:СϪˮ",
						"�ر���ԭ:ɣ�Ѻ�ˮ",
						
						"����:��ˮ",
						"̩ɽ:ɽ��ˮ",
						"����:��¶ˮ",
						"���:�껨��ˮ",
						"̩ɽ:��Ҷ̶ˮ",
						"�ر�ɳĮ:С����ˮ",
					});
					
						
	message_vision("½��ҡҡͷ˵��������ˮ����һ�첻��һ���ˣ�û�к�ˮ����ô�ݺò裡\n\n", me);
	
	if (!QUESTS_D->verify_quest(me,"��̽ˮ��"))
		return 1;
	
	if ( me->query("quest/quest")!="��̽ˮ��")
		return 1;
		
	if (me->query("combat_exp")< 50000)	pos = source[random(23)];
	else if (me->query("combat_exp")< 100000) pos = source[23 + random(7)];
	else pos = source[30+ random(6)];
	
	if (sizeof(me->query_temp("luyu"))){
		tell_object(me,CYN"½��˵���ҽ����������¶�������ô����Ҫ��"+ me->query_temp("luyu/area") +"��
��ü��۵Ĳ����һ��" + me->query_temp("luyu/water") + "������\n"NOR);
		return 1;
	}	
	
	if (sscanf(pos,"%s:%s", area, water)!=2)
		return notify_fail("Please inform wizard about this bug.\n");
	
	me->set_temp("luyu/area",area);
	me->set_temp("luyu/water",water);
	me->set("quest/short","��ü��۵Ĳ����"+ me->query_temp("luyu/area")+"��һ��"+
me->query_temp("luyu/water")+"��������½��");
	
	tell_object(me,CYN"½��˵�����ܲ��ܰ��Ҹ�æ����"+ me->query_temp("luyu/area") + "��
��ü��۵Ĳ����һ��" + me->query_temp("luyu/water") + "������\n");	
	tell_object(me,"½��˵�����뿴���ǲ����Ժ�ʹ��Ƕ���ˮ������\n"NOR);	
	return 1;	
}

int accept_object( object me, object ob){

	if (ob->query("name")!="���")	return 0;
	
	if (!QUESTS_D->verify_quest(me,"��̽ˮ��")) return 0;
		
		
	if (ob->query("mark")!= "luyu") {
		command("say ��ѽ����ôû����ü��۵Ĳ�����ⲻȫ������ô��");
		return 0;
	}
	
	if (ob->query("liquid/name")!= me->query_temp("luyu/water")){
		command("say �ⲻ����Ҫ�Ե�ˮ��\n");
		return 0;
	}
	
	me->delete_temp("luyu");
	command("touch "+ me->query("id"));
	command("say ̫лл�ˣ������ȥ�ݺ��賢����");
		
	if (QUESTS_D->verify_quest(me,"��̽ˮ��"))
		QUESTS_D->special_reward(me,"��̽ˮ��");
			
	return 1;

}


void reset(){
	        set("vendor_goods", ([
//	        			"/obj/medicine/party/pill_qingtuan": 50,
                "/obj/food_item/luteapot": 50,
                "/obj/food_item/dumpling": 50,
                "/obj/food_item/chicken_leg": 50,
                __DIR__"obj/longjin":50,
// "/obj/wiz_toy/taskstone1": 150,
        ]) );
}