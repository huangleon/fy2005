inherit ROOM;
void create()
{
        set("short", "�����ϳ���");
        set("long", @LONG
�������Ÿ����ɣ���Լ�������࣬�����ĳ�����������ȭͷ���С��������
�Ŷ���Լ���ɣ���Լÿ������ʱ���ͻ��ٱ����ء���������������׽��֮��Ĺ�
��ͨ������ٷ��轻��������䣱�����ƽ𣩡��Ŷ���������һ���ϳ�ǽ��խ�ݡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"swind5",
]));
        set("objects", ([
        __DIR__"npc/wind_solider" : 2,
        __DIR__"npc/cloud_solider": 2, 
			]) );
        set("outdoors", "fengyun");
        set("coor/x",0);
        set("coor/y",-60);
        set("coor/z",-300);
        setup();
}


