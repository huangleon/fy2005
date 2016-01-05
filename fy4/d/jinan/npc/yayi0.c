#include <ansi.h>
#include <command.h>
inherit NPC;
int qijiao();

void create()
{
        set_name("�������", ({ "chaiyi"}) );
        set("long", "���ڵ���Ĳ��ۣ����������ү�Ǳ��Ρ�(jiaozi)\n");
        set("attitude", "heroism");
	set("vendetta_mark", "authority");
	set("reward_npc", 1);
	set("difficulty", 5);

        set("cor", 40);
        set("cps", 25);

        set("combat_exp", 4000000);

	set("inquiry", ([
        	"����" : 	(: qijiao :),
             	"jiaozi" : 	(: qijiao :),
              	"jiao zi" : 	(: qijiao :),
   	]));

        set_skill("unarmed", 200);
        set_skill("staff", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("move", 200);
	set_skill("fumostaff",200);
	set_skill("meihua-shou",150);
	set_skill("puti-steps",200);
	
	map_skill("dodge","puti-steps");
	map_skill("staff","fumostaff");
	map_skill("unarmed","meihua-shou");
	map_skill("parry","fumostaff");
	
        set("chat_chance", 1);
        set("chat_msg", ({
        }) );

        setup();

        carry_object(__DIR__"obj/yafu")->wear();
        carry_object(__DIR__"obj/sawei")->wield();
}

int qijiao() {
	object me;
	string jiaozi;
	me=this_player();
	if (me->query("class")!="official") {
		command("say ����ʲô�ˣ���ʲô�ʸ����ٽΣ�");
		return 1;
	}
	if (me->query("family/master_id")=="master yue") {
		message_vision("$N�ϻ̳Ͽֵض�$n˵����С������Ĺٽ��Ǹ��Ĺٴ��˱��ģ�������������ɡ���\n",this_object(),me);
		return 1;
	}
	if (me->is_fighting()) {
		message_vision("$N˵�������˻����¶�û������ɣ���\n",this_object());
		return 1;
	}
	
	if (me->query("combat_exp")>5000000) jiaozi=HIG"����"+HIY"�𶥴��"NOR;
		else if (me->query("combat_exp")>2500000) jiaozi=RED"����ľ���"NOR;
		else jiaozi=BLU"����ڶ����ؽ���"NOR;	
		
	message_vision("�ĸ��η�̧��һ��"+jiaozi+"���˹�����\n",this_object());
	message_vision("$N�������ӣ�$n����ߺ�ȣ���"+me->name()+"�������ඣ���\n",me,this_object());
	me->start_busy(4);
	call_out("go_out_1",2,me,jiaozi);
	return 1;
}

int go_out_1(object me,string jiaozi) {
	object room;
	if (me->is_ghost()||me->is_fighting()) return 1;
	room=find_object(AREA_FY"fysquare");
	if(!objectp(room)) 
        	room = load_object(AREA_FY"fysquare");
        me->move(room);
        message_vision("$N����"+jiaozi+"���˹�����\n",me); 
        call_out("go_out_2",2,me,jiaozi);
        return 1;
}

int go_out_2(object me,string jiaozi) {
	object room;
	if (me->is_ghost()||me->is_fighting()) return 1;
	room=find_object(AREA_QUICKSAND"greenland");
	if(!objectp(room)) 
        	room = load_object(AREA_QUICKSAND"greenland");
        message_vision("$N����"+jiaozi+"�����뿪��\n",me);
        me->move(room);
        message_vision("$N����"+jiaozi+"���˹�����\n",me); 
        call_out("go_out_3",2,me,jiaozi);
        return 1;
}

int go_out_3(object me,string jiaozi) {
	object room;
	if (me->is_ghost()||me->is_fighting()) return 1;
	message_vision("$N����"+jiaozi+"�����뿪��\n",me);
	room=find_object(AREA_CHENXIANG"yam");
	if(!objectp(room)) 
        	room = load_object(AREA_CHENXIANG"yam");
        message_vision("$N����"+jiaozi+"���˹�����\n",me); 
         me->move(room);
        message_vision("$N�����Ĺٷ����߳����ӡ�\n",me);
        return 1;
}
