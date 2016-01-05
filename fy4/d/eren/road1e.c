inherit ROOM;
#include <ansi.h>
#define FATEMARK "����A/����_����"

void create()

{
        set("short", "��·");
        set("long", @LONG
·����һƬ���̵���Ұ��Ũ������ԡ�����ɫ��ɽ���ϣ�һ�������ɫ���ݶ�
��̫�������Ź⡣��һ��ʯ��·ͨ��Ԭ�ҵİ���ׯ��·�ڳ���һ�ô���������
�м�����������ЪϢ��
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"road1d",
		"north": __DIR__"yuanvillage",

	]));
        set("objects", ([
        	
	]) );
	set("item_desc", ([
		"����":	"�������Լ���ϰ����ˣ�Ũ��������ա�\n",
		"����":		"�������Լ���ϰ����ˣ�Ũ��������ա�\n",
		"tree":		"�������Լ���ϰ����ˣ�Ũ��������ա�\n",       	
	]) );
	set("outdoors", "eren");
        set("coor/x",-50);
        set("coor/y",10);
        set("coor/z",10);
	set("map","eren");
	setup();

}


void init(){

	add_action("do_climb","climb");
}

int do_climb(string arg)
{
        object 	me;
		me = this_player();
		if (me->is_fighting() || me->is_busy())
		{
			write("��������æ���ղ�������������\n");
			return 1;
		}

		if(!arg) 
		{
			write("��Ҫ�������\n");
			return 1;
		}

		if( arg == "up" || arg == "tree" || arg=="��" || arg == "����"
			|| arg == "����")
        {
				message_vision("$N�ֽŲ��ã����������������ȥ��\n",me);
				me->perform_busy(2);
        		call_out("fliping",2,me);
        		return 1;
        }
        else
        {
                write("�㲻������"+arg+"��\n");
                return 1;
        }
}


int fliping(object me)
{
		object room;
		if( !me->is_ghost() && environment(me) == this_object()) 
		{
			room=find_object(__DIR__"tree1");
			if (!objectp(room)) room=load_object(__DIR__"tree1");
			tell_room(room, me->name() + "�Ӵ���������������\n");
			me->move(room);      		
		}
        return 1;
}


void init_scenery()
{
        remove_call_out("flower_drop");
        call_out("flower_drop",1, random(2), 0);
}

void add_fate_mark(object ob)
{
	int num = 1 + random(10);
	if(!random(3)) {
		ob->set(FATEMARK,num);
		log_file("riddle/FATE_LOG",
			sprintf("%s(%s) �õ�"+FATEMARK+" "+num+"�� %s \n",
				ob->name(1), geteuid(ob), ctime(time()) ));
	}
}


void flower_drop(int sunrise, int sunrise_stage)
{
	object *ppls;
    	object ob;
    	function f = (:add_fate_mark:);
    	ob = this_object();
    	
    	message("vision", WHT"\n����ķ紵����������Ҷ�ӷ���ɳɳ����������Ƭǳ��ɫ�Ļ�����Ʈ��������\n"NOR, ob);
        message("vision", WHT"��ʪ�ķ�������ŵ����������������˾���Ϊ֮һˬ��\n"NOR, ob);
	ppls=filter_array(all_inventory(ob),(:userp($1) && interactive($1) && !$1->query(FATEMARK):));
        if(sizeof(ppls))
		map_array(ppls,f);
}