// silencer@fy4 workgroup 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��Ѫ��");
	set("long", @LONG
���Ӻ���һ��һ�ɼ����ĳ��ӣ�����Ư����ʬ�ǣ������ҩ�ݣ�������ɫ��
Һ�壬����ð��Ѫ��֮��������һ��Χ��ʮ����ͭ���������������ƣ����ڻ�����
���⡣�������Ʋ����ҵ���Ѫ�ء� 
LONG
	);
	set("no_clean_up", 0);
	set("no_fly",1);
	set("exits",([
		"north" : __DIR__"cave-exit",

	]));
	set("objects", ([
                __DIR__"npc/cv-yecha1": 1,
                __DIR__"npc/cv-yecha2": 1,
                __DIR__"npc/cv-yecha3": 1,
                __DIR__"npc/cv-yecha4": 1,
        ]) );
	
	set("item_desc", ([
        	"��Ѫ��":	"
һ�ɼ�������Ѫ�أ�����Ư����ʬ�Ǻ����̵�ҩ�ݡ���������Խ�����Ͷ����throw����ȥ��\n",
        	"pond":	"
һ�ɼ�������Ѫ�أ�����Ư����ʬ�Ǻ����̵�ҩ�ݡ���������Խ�����Ͷ����throw����ȥ��\n",
	]) );
	setup();
	
}


void	init(){
	add_action("do_throw","throw");
}


int	do_throw(string arg){
	object seed, me, *inv, item, guard;
	mapping data;
	me = this_player();
	if (!arg) 
		return notify_fail("��ҪͶ��ʲô��\n");
	
	inv = all_inventory(this_object());
	foreach (object ob in inv) {
		if (ob->query("sq_guard")) {
			ob->kill_ob(me);
			return notify_fail(ob->name()+"Х��һ�������㷢��������\n");
		}
	}
		
	inv = all_inventory(me);
	foreach (object ob in inv){
		if (ob->query("name")==arg || ob->query("id")==arg) {
			item = ob;
			break;
		}
	}
	if (!item)
		return notify_fail("��û�������Ʒ��\n");
	if( userp(item))
                return notify_fail("�㲻���ջ�Ķ�����\n");
        if( item->query("owner")|| item->query("no_burn"))
                return notify_fail("�������������ա�\n");
	
	if (query("burnt"))
			return notify_fail("��Ѫ���Ѿ����ո��ˡ�\n");

	if (item->query("name")==RED"�������"NOR) {
		message_vision(HIG"$Nһ˦�֣����������Ͷ����ڣ����һ���������Ѫ������������������ \n"NOR,me);
		if (!REWARD_D->check_m_success(me,"�ǻ�Ѫ��"))	
		{
			REWARD_D->riddle_done(me, "�ǻ�Ѫ��",100, 1);
			data = ([
				"name":		"�ƽ������ǻ�Ѫ��",
				"target":	me,
				"att_1":	"cps",
				"att_1c":	1,
				"mark":		1,
			]);
			REWARD_D->imbue_att(data);
		}
		
		me->start_busy(8);
		set("burnt",1);
		call_out("burning",10, me);
		call_out("hint",60, me);
		destruct(item);
		return 1;
	}
	message_vision(HIG"$Nһ˦�֣���"+item->name()+"Ͷ����ڣ����һ����ð��һ˿���̣����ܵ���Ӱ�����ˡ�\n"NOR,me);
	destruct(item);
	return 1;
}

// ���jade is bonus, not required to continue riddle.
//	Here we will allow ��Щ�Ѿ��õ����׵��˿���jade,û����û������.

int burning(object me){
	
	object pill;
	message_vision(RED"������С����ȥ����Ѫ���е�Ѫˮ��ʬ�ǣ�ҩ������ȫ���յ�һ�ɶ����� \n"NOR,me);
/*	if (me->query("maze/����")) {
		message_vision(RED"����ȼ������Ѫ�ؿտ���Ҳ��ȴ����һ����˸������Ĺ�Եı�Ѫʯ��\n"NOR,me);
		pill = new(__DIR__"obj/jade_1");
		if (pill) { 
			pill->move(this_object());
			pill->set("owner",me);
		}
	}*/
	return 1;
}

// This hint is also not required to continue.
int hint(object me){
	tell_object(me,GRN"
������ؿ��������ǣ���ϸ������������˫�ֲ����˹�������ߡ��������
��֮�ģ�Ī��Ⱦ���˲����ң����ǸϿ��Ҷ��˷��ʸ�����ɡ� \n"NOR);
	return 1;
}


void reset(){
	set("burnt",0);
	::reset();
}