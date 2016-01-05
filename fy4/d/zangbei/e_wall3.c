inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "��կǽ");
        set("long", @LONG
կǽ���ռ�¥�ĸ�ʽ�����ģ�һ�������㶼�м��ۣ�����ֻ��һ��ǽ�ڣ�����
���Ҳ��¶��ͷ�������������������������կ�����վ��ǽ������������Ӹ���
�£�ʮ�ֵ��֡�կǽ������ï�ܵ�ɭ�֣�կǽ������Կ���һ����Ժ��Ժ�ӵ�����
�м����߷�����ǽ��һ�ѳ��ݹ������¡�
LONG
        );
        set("exits", ([ 
		"northwest":	__DIR__"e_wall2",
	]));
        set("item_desc", ([
        	"ladder": "һ�ѳ��ݴ�կǽ��ͨ���Ժ�����������ȥ��climb down����
�������������������⵽���˹��������»�Դ����\n",
        	"����":	 "һ�ѳ��ݴ�կǽ��ͨ���Ժ�����������ȥ��climb down����
�������������������⵽���˹��������»�Դ����\n",        
        ]));
        
        set("objects", ([
        	__DIR__"npc/archer":	2,
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1480);
        set("coor/y",580);
        set("coor/z",10);
	set("map","zbwest");
	setup();
}


void init() {
	add_action("do_climb","climb");	
	add_action("do_yell","yell");
	 if(interactive(this_player()))
    {
         remove_call_out("do_hints");
         call_out("do_hints",random(10)+10,this_player());
    }
}

int do_hints(object me)
{
    if (! me || environment(me)!=this_object())	return 1;
    message_vision(WHT"ǽ�´���ߺ������կ�ϵ��ֵ�С���ˣ����е����������ٺ��У�yell��կ��������\n"NOR,me);
    return 1;
}


int do_yell(string arg){
	object me, boss, room;
	string *boss_name=({"baimian langzhong","tu laohu","one eye"});
	string boss1;
	int i,num;
	string file;
	
	me = this_player();
	room = this_object();
	
	if (present(boss_name[0],room) || present(boss_name[1],room)
			|| present(boss_name[2],room)) {
		tell_object(me,"�����Ȱ���ǰ��ǿ���������˵�ɡ�\n");
		return 1;
	}
	
	if (!arg || (arg!="����" && arg!="������" && arg!="������")) {
		tell_object(me,"������ĸ�������������������������������\n");
		return 1;
	}
		
	message_vision(YEL"$Nѧ��ɽկ��޵�ǻ����е�������������"+arg+"������������\n"NOR, me);

	switch (arg) {
		case "����": 	boss1 = "one eye"; break;
		case "������":  boss1 = "baimian langzhong"; break;
		default:		boss1 = "tu laohu";
	}
	
	boss=find_real_living(boss1);
/*	if (boss) {
		write("boss is " + file_name(boss)+"\n");
		if (sscanf(file_name(boss),"%s#%d",file, num)!=2)	write ("bad boss is" + living(boss) + "\n");
	}*/
	if (boss && !boss->is_fighting()) {
		boss->command("say �����̵ģ������������ң�");
		boss->move(room);
		boss->start_busy(2);
		message_vision(CYN"կǽ��һ��ɧ������һ���Դ���������ð�˳�����
$N˵��ʲô�˸ҵ�����կ�����ң����Ұ������Դ�š������ƣ�����\n"NOR,boss);
		boss->kill_ob(me);
		me->kill_ob(boss);
		return 1;
	}
		
	tell_object(me,"�����ã�կ��ʲô����Ҳû�С�\n");
	return 1;		
}	

void reset() {
	object *inv, room;
	int i;
	
	::reset();
	inv=all_inventory();
	
	for (i =0; i<sizeof(inv); i++) {
		if (inv[i]->query("longhu_boss") 
			&& !inv[i]->is_fighting()) {
			inv[i]->ccommand("say �����Ǻúÿ���ɽկ����ȥЪϢһ��");
			room=find_object(AREA_ZANGBEI"village");
			inv[i]->move(room);
			message_vision("$N��ɽկ�������˽�����\n",inv[i]);
		}		
	}		
}			
	
int do_climb(string arg) {
	
	object me;
	
	me=this_player();
	if (arg=="down" || arg == "ladder" || arg== "����") {
		if (me->query_temp("zangbei/zaiqiang_1"))
			return notify_fail("���Ѿ������������ˡ�\n");
		message_vision("$N���ų���С�������������ȥ��\n\n",me);
		call_out("pass_river",4,me);
		me->start_busy(6);
		me->set_temp("zangbei/zaiqiang_1",1);
		return 1;
	}
	tell_object(me,"��Ҫ��ʲô��\n");
	return 1;
}


int pass_river(object me) {
	object room;
	if (!objectp(me) || me->is_ghost()) return 0;
	room=find_object(__DIR__"village");
	if (!objectp(room)) room=load_object(__DIR__"village");
	tell_object(me,"�����ɵ��µ�Ժ���\n");
	message("vision",me->name()+"������������������\n",room);
	me->move(room);
	me->delete_temp("zangbei/zaiqiang_1");
	return 1;
}

