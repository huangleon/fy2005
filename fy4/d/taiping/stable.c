#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��վ��");
        set("long", @LONG
���뽡�����������ԣ�ÿ����վ������ר�ŵ���������ش�����������
���Դ�����֫ϸ����������Сë����ë��ϡ������������죬���ڵ����ֹ���
˶�󣬳���³��һ��������ȫ��ͬ�������������߸�С�䣬��������Ųݡ�
LONG
        );
        set("exits", ([ 
		"south":  __DIR__"yizhan",
	]));
        set("objects",([
        	__DIR__"npc/labor": 1,
        	__DIR__"obj/corner":	1,
         ])  );
        set("item_desc", ([
		"��":	"�������߰���ض��ڽ����\n",
        	"wood":	"�������߰���ض��ڽ����\n",               
        	"grass":"�������߰���ض��ڽ����\n",               
	 ]));
	set("mouse",5);
	set("coor/x",10);
	set("coor/y",5);
	set("coor/z",0);
	set("map","taiping");
	setup();
}


void reset(){
	object item, coffin;
	object *inv, *players;
	::reset();
	if (!objectp(coffin=present("corner",this_object()))) return;
		
	if (!present("broken rake",coffin)) {
		item=new(__DIR__"obj/brokenrake");
		item->move(coffin);
	}
	if (!present("gao",coffin)) {
		item=new(__DIR__"obj/gao");
		item->move(coffin);
	}
	set("mouse",5);
	return;
}

void init()
{
        add_action ("do_clean", "clean");
}


int do_clean()
{		
	object me,mouse;
	int eff_kee,amount;
        
        me=this_player();
        if (!present("broken rake",me)) 
        	return notify_fail("������û�аǲݵĹ���ѽ��\n");
        
        eff_kee = me->query("kee");
        if (eff_kee < (int)this_player()->query("max_kee")/10) 
        	return notify_fail("��̫���ˣ���ô�ǲݣ�\n");
                
        if (me->is_busy())
        	return notify_fail("��������æ��\n");
        	
	me->start_busy(2);
	me->receive_damage("kee",(int)this_player()->query("max_kee")/10);
	message_vision(CYN"$N���Ŷ��Ѷ�����˵��Ū����������
������һ�����������ڸɾ���һЩ��\n\n"NOR, me);
        
        if (me->query_skill("fork",1)<=50) {
        	amount =  ((me->query("int") + me->query("cps"))*10);
      		if(amount < 1) amount = 1;
      		me->improve_skill("fork", amount);	
        }
        if (!random(5) && query("mouse")){
        	mouse=new(__DIR__"npc/mice");
        	mouse->move(this_object());
        	message("vision","�ݶ������������һֻ"+mouse->name()+"��\n",this_object());
        	add("mouse",-1);
        }
	return 1;
}


int go_out_1(object me, int stage) {
	object room;
	string *route = ({AREA_TAIPING"yizhan",AREA_TAIPING"mroad1",  
				AREA_ZANGBEI"kunlun1",AREA_QUICKSAND"yangguan", 
				AREA_QUICKSAND"saiwai2", AREA_QUICKSAND"saikou", 
				AREA_QUICKSAND"yizhan" });
				
				
	string *dir = ({ "��","��","��","��","��","��","��" });
	
	if (!me || me->is_ghost())	return 1;
		
	if (me->is_ghost()||me->is_fighting()) {
		tell_object(me,"�������������������\n");
		me->stop_busy();
		me->delete_temp("ride");
		return 1;
	}
	
	room=find_object(route[stage]);
	if(!objectp(room)) room = load_object(route[stage]);
        message_vision("$N����������"+dir[stage]+"�뿪��\n",me);
        me->move(route[stage]);
        message_vision("$N�����������˹�����\n",me); 
//	write ("stage is "+stage+" route is "+sizeof(route)+"\n");
	stage++;
	if (stage == sizeof(route)) {
		message_vision("������һ��ߺ�ȣ������ˣ���\n",me);
		message_vision("$N�����ձ���һԾ���¡�\n",me);
		me->delete_temp("ride");
		me->stop_busy();
		return 1;
	}
	call_out("go_out_1",2,me, stage);
        return 1;
}

