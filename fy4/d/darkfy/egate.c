inherit ROOM;
void create()
{
        set("short", "���ƶ�����");
        set("long", @LONG
���ƶ��Ÿ����ɣ���Լ�������࣬�����ĳ�����������ȭͷ���С��������
�Ŷ���Լ���ɣ���Լÿ������ʱ���ͻ��ٱ����ء���������������׽��֮��Ĺ�
��ͨ�����Ŷ���������һ���ϳ�ǽ��խ�ݡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"ecloud5",
]));
        set("objects", ([
        __DIR__"npc/wind_solider" : 2,
        __DIR__"npc/cloud_solider": 2, 
			]) );
        set("outdoors", "fengyun");
        set("coor/x",60);
        set("coor/y",0);
        set("coor/z",-300);
        setup();
}


