//mac's qiyan.c
#include <room.h>

inherit ROOM;

void create()
{
  set("short","���̾ŵ�");
  set("long",@LONG
һ�����Ʒ���������ʯ�����ɽ���ϣ������ĸ����֣����̾ŵ㡣ɽ������ս
��ʱ��³��������ĵ��̡����¸��ӿ��Կ���Զ�����ϳ��̴��ϵĴ��̼�ɽ���¸�
���ε�˴��ɽׯ����ɽ�Ĺ����Լ��˳ǵ��˶������ݴ˿ɼ�һ�ߡ�
LONG
  );
  set("exits",([
         "westdown":AREA_JINAN"tanghuai.c",
         "eastup"  :__DIR__"fudi.c"
               ]));
        set("objects", ([
                __DIR__"npc/monk" : 2,
       ]) );
        set("outdoors", "qianfo");
	set("coor/x",-10);
	set("coor/y",-100);
	set("coor/z",-20);
	setup();
  replace_program(ROOM);
}
