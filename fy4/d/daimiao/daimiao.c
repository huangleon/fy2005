
#include <room.h>
inherit ROOM;
void create()
{
  set("short","���");
  set("long",@LONG
ң��ͤ�����֮����������������緻��������Ъɽʽ��ľ�ṹ�������գ�
����������ܽǷ��̣��������ۡ�����֮�������ű�ƿ���������Ĵ���ק���ӹ̡�
����С������͸���Ŷ���Ϸ�飬�������ϸ����ŵ��ﳯ�������µ�������ʯ������
�Ͼ�����˫�������²��ǹ���ʯ��ʯ��ǰ���������ʨ���ԣ�����Ϸˣ���򣬴���
������ʨ����̬���죬�����ɰ���
LONG
  );
  	set("exits",([
        	"north":__DIR__"zhengyan.c",
         	"south":__DIR__"yaocan.c",
         	"northwest": __DIR__"w_yemen",
         	"northeast": __DIR__"e_yemen",
        ]));
        set("objects", ([
        
       	]) );

	set("coor/x",0);
	set("coor/y",-60);
	set("coor/z",0);
	setup();
  
}
