#include <room.h>
inherit ROOM;

void create()
{
  set("short","˫����");
  set("long",@LONG
˫���ؽ�����������꣬��ʯ������������Χ������ĸ��֮ˮ������������
����ڡ����ڳص������Ͷ��Ͻ��ϸ���ʯ����ͷһ����ר������ˮ֮�ã����Գ�Ϊ
��˫���ء����ر���Ļ����ϴ����š���Ծ��ء��ĸ��֡���ǰΪͨ��֣�������
Ѳ֮ʱ���Ĺ��½Ρ�������������ڽ�����ӭ�����ӡ�
LONG
  );
  	set("exits",([
        	 "north":__DIR__"yaocan",
         	"southwest":AREA_JINAN"road4",
        ]));
        set("objects", ([
		__DIR__"npc/tiao" : 2,
       	]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",0);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
  	
}
