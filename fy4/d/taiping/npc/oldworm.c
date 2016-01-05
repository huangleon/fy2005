#include <ansi.h>
inherit SMART_NPC;
inherit __DIR__"timeshift";
inherit F_VENDOR;
inherit INQUIRY_MSG;

int blinding();
int bbqthem(object me, object obj);

void create()
{

	set_name("�ϻ׳�",({"oldworm"}));
    	set("long", "
�԰׵�ͷ����������������������׳棬���е����Ǹ�Ϻ�ס���һ���������Ƶ���
������Ȼ��ƣ�룬�ֲ��ϣ�һ˫�۾���ȴ���Ǵ��Ŷ������Ц�⡣\n");
	set("title","�ӻ����ϰ�");
	set("age",60);
	set("combat_exp", 8000000);
    
    set("reward_npc", 1);
	set("difficulty",10);
		
	set("attitude","friendly");
		
	set("day_room","/d/taiping/zahuo");
	set("shift/day_leave","$N�Ҵ�ææ���뿪�ˡ�\n");
	set("shift/day_arrive","$NЦ�Ǻǵ��߹���˵�����ӻ��̿���ඡ���\n");
	set("night_room","/d/taiping/droad4");
	set("shift/night_leave","$N̽ͷ���˿���ɫ˵����ʱ�䲻�磬����ඡ����漴�������˳�ȥ��\n");
	set("shift/night_arrive","$Nһ����������˹�����\n");
	
	set("dinner_room","/d/taiping/laodian");
	set("shift/dinner_leave","$N���˸����������Է���ʱ�䵽ඡ���˵��������ȥ��\n");
	set("shift/dinner_arrive","$N�߹����ڰ�����������������\n");
	set("shift/after_dinner","$N���¿��ӣ�������������ȥ��\n");
	set("shift/back_dinner","$N���ű������˹�����\n");
			
	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
		10: 	(: blinding() :),
    ]) );    	
        
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
     }) ); 		

	auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","taiji",2);
	
	set_skill("iron-cloth",150);
	set_skill("xisui",100);
	map_skill("iron-cloth","xisui");
	add_temp("apply/damage",110);
		
    set("vendor_goods", ([
            "/obj/food_item/chicken_egg": 40,
            "/obj/food_item/duck_egg": 40,
            "/obj/food_item/quail_egg":	40,
            "/obj/food_item/goose_egg":	40,
            "/obj/medicine/cough_drug": 40,
            "/obj/medicine/drug_qicaibat": 40,
            "/obj/medicine/drug_bat": 40,
    ]) );
	setup();
	carry_object(__DIR__"obj/hat2")->wear();
	carry_object(__DIR__"obj/pant")->wear();
}


void init() {
	
	object me;
	::init();
	if( interactive(me = this_player()) && !is_fighting() ) {
		remove_call_out("shifting");
		call_out("shifting", 1, me);
	}
        add_action("do_vendor_list", "list");

}

void die() {
	
	object me, ob, owner;
	ob=this_object();
	
	if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) me = owner;
		
	if (me)
	if(file_name(environment(ob))==AREA_TAIPING"droad4") {
		message_vision(WHT"\n�ϻ׳�������𣬱�ǹһ�����Ϸ�ȥ���ӹ�ˮ�����ӹ��峵���ۿ���Ҫ�ӳ���ǽ����\n\n"NOR, ob);
		message_vision(BLU"��Ȼ��ƽ�峵�ϵ�ʬ�徹��ӵ��Ϸ���������"WHT"

�ƹ�ɲ�����������ʬ������ӡ�		

"HIY"����ү��"NOR+WHT"

����үһ�����һȭ�����ϻ׳������֮�ϡ�

��һȭ�ϻ׳��Ѳ��ܶ�ܣ������ա�һ�£���ͷ�������죬���������Ͱ�����ȥ��
������������ȴ����������ײ��ǽ�ϡ�

����үٿ��һ����Ծ�������Աߵ�һ��������ʧ�ˡ�\n"NOR, ob);
		me->set("marks/parrot/�ϻ׳�֮��",1);
	}
	::die();
}
	
int blinding() {
	environment(this_object())->blinding(this_object());
	return 1;
}

void reset()
{
        set("vendor_goods", ([
                "/obj/food_item/chicken_egg": 40,
                "/obj/food_item/duck_egg": 40,
                "/obj/food_item/quail_egg":	40,
                "/obj/food_item/goose_egg":	40,
                "/obj/medicine/cough_drug": 40,
                "/obj/medicine/drug_qicaibat": 40,
                "/obj/medicine/drug_bat": 40,
        ]) );
}
