inherit ROOM;
void create()
{
        set("short", "����������");
        set("long", @LONG
�����Ÿ�С���ƾɣ��س�����б���ź�ӣñ��§�ų�ǹ�ڴ��˯��Ҳ����Ϊ
��������ס��ƶ���õ�֮ͽ��������ΰ������������Ǻܺá�����ӹ�֮ʱ������
���������裬ҹĻ����֮�󣬲Һź���Ц������˷���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"wcloud5",
]));
        set("objects", ([
        __DIR__"npc/wind_solider": 2, 
			]) );
        set("outdoors", "fengyun");
        set("coor/x",-60);
        set("coor/y",0);
        set("coor/z",-300);
        setup();
}


