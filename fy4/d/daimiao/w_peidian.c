#include <room.h>
inherit ROOM;

void create()
{
  	set("short","�����");
  	set("long",@LONG
ң��ͤ���������Ƕ����������䣬ǰ����ʽ���ϸ��������ߣ�����������
����۹����̡����������鱮���������ܵ�����͡��η���̳�̱�����ǰ������
���ܵ���޽����飬���������������ڵ�̩ɽ���ݴ�л�������顱�������Ȼ��
���������ռ���������������ͳ���������ʱ��Ѻ����֮�˵ĵط���
LONG
  );
//  	set("exits",([
//        	 "east":__DIR__"yaocan",
         	
//        ]));
        set("objects", ([
                
       	]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",-10);
	set("coor/y",-65);
	set("coor/z",0);
	set("no_fly",1);
	setup();
  	
}

void reset(){
	object room, *inv;
	int i, num;
	::reset();
	room = this_object();
	inv = all_inventory(room);
	i = sizeof (inv);
	while (i--) {
		if(userp(inv[i])) {
			tell_object(inv[i],"�����Ĵ��ź��һ�����ˣ��㱻һ�����˳�ȥ��\n");
			tell_object(inv[i],"����������һ������˵�����������������һ����·����\n");
			inv[i]->delete_temp("daimiao/spy");
			inv[i]->move(__DIR__"yaocan");
		}
	}
}

