#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY"��̳"NOR);
    set("long",
"��̳Ϊ������������֮���ڣ�����ׯ�����£�������Բ�ط������������ֳʻ�
���Σ���������̳����̳��ʮ�˸���˿�ľ��������Ȧ���ĸ�Ԣ�ⴺ���ﶬ�ļ���
�м�ʮ����Ԣ��ʮ�����£�����ʮ����Ԣ��ʮ��ʱ���Լ��������ޡ���������ࡢ
�лơ�������ɫ������Ԣ���졢�ء�����������ϸ������ң�"+HIY"

                      ��         ̳
                      
"NOR 
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"nwind1",
	"south" : __DIR__"fysquare",
	"east"  : __DIR__"fyge", 
"west"  : __DIR__"lotto", 
      ]));
    set("outdoors", "fengyun");
    set("objects", ([
	//        __DIR__"npc/mei": 1,
      ]) );

    set("coor/x",0);
    set("coor/y",40);
    set("coor/z",0);
    set("map","fynorth");
    setup();
    replace_program(ROOM);       //add by ldb ϣ��ˢ�����ߵ�NPC 

}
