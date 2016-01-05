#include <ansi.h>
inherit ROOM;

int do_suli();
void load_item(object me);

void create()
{
    set("short", "��ڼ�");
    set("long", @LONG
һ��ֻ��һ���˵�С���䡣�����һ��ǽ���пף�������������Ժ������Ĵ�
�����ڡ�������ֻ����Сľ�ʺͶ���ǽ�Ϲ��˷Ŷ�����ľ�壬���������˶�����
���������������ʲô��������ͷ��ֻҪ�������������ڣ������������ϴ��
���棬����һ�г��������ǣ�ң��������ˡ�����㶪��ʲô��Ҫ�Ķ�����Ҳ����
������һ���������ϲԵĶ��͡�
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"church",
      ]));
    set("objects", ([
	__DIR__"npc/chantou" : 1,
      ]) );
    set("coor/x",20);
    set("coor/y",-70);
    set("coor/z",0);
    set("map","fysouth");
    setup();
}

int	init() {
	add_action("do_suli","pray");
}


int	do_suli(){
	object me;
	me = this_player();
	if (me->is_busy())
		return notify_fail("��������æ��\n");
	message_vision(YEL"$N�Ϲ��Ͼ��ع��£�˫��������ǰ������ͷ��ʼ��ڡ�\n"NOR,me);
	tell_object(me,"�㻮��ʮ�ַ��ģ������ҽ��һ��С�Ĳ��ٶ������ˡ�����\n");
	me->start_busy(3);
	call_out("load_item",4,me);
	return 1;
}


void load_item(object me)
{
	int MAX = 3;
	string name,id, *created, my_item, inv_item;
	int j, i, got_one;
	object thing, *inv;

	id = me->query("id");
	if (!objectp(me) 
		|| environment(me)!=this_object() 
		|| me->is_ghost())
		return;

	created = get_dir(DATA_DIR + "login/" + id[0..0] + "/" + id + "/");
	for(j=0; (j<sizeof(created) && j < (MAX+1) ); j++)
	if( sscanf(created[j], "%s.c", name) == 1 )
		{
			got_one = 0;
			my_item = DATA_DIR + "login/" + id[0..0] + "/" + id + "/" + name + ".c";
			inv = all_inventory(me);
			i = sizeof(inv);		
			if (i>=14)	return;	//���ⶫ��̫������ɴ�Ͳ����ˡ�
			while (i--) {
				if(inv[i]->query("weapon_prop") && inv[i]->query("owner") == id ) {
					inv_item = base_name(inv[i])+".c";
					if (inv_item == my_item) 
						got_one = 1;
				}
			}
			if (!got_one) {	
				thing = new(my_item);
				thing->restore();
		
/*		thing->set("weapon_prop/karma",me->query("imbue_prop/karma"));
		thing->set("weapon_prop/composure",me->query("imbue_prop/composure"));
		thing->set("weapon_prop/strength",me->query("imbue_prop/strength"));
		thing->set("weapon_prop/agility",me->query("imbue_prop/agility"));
		thing->set("weapon_prop/intelligence",me->query("imbue_prop/intelligence"));*/

				// *sing*

				if(thing->move(me))  
					message_vision( thing->name() + "һ����Ծ����$N���У���\n",me);
					else write("error when moving to player.\n");
			}
		}
	me->set_temp("already_loaded",1);
	message_vision("$N�����ϣ��ϻ̳Ͽֵ�վ��������\n",me);
}