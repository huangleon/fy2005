inherit ROOM;
void create()
{
        set("short", "���ƴ�·");
        set("long", @LONG
�����Ƿ��Ƴ������̾��������߻켯֮�����������Ǵ�ٹ��ˣ����Ƿ������䣬
ֻҪ����������Ǯ����������ͻ��ܵ�������к����κ��㲻֪�����£��������
��һ�£�������֪�����˾Ų���ʮ���������������˵ģ�����ģ�����ߵģ�����
�ģ���ҩ��...��Ӧ�о��С�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"ecloud4",
  "west" : __DIR__"ecloud2",
  "north" : __DIR__"smithy",
  "south" : __DIR__"washroom",
]));
        set("objects", ([
        __DIR__"npc/" : 1,
			]) );

        set("outdoors", "fengyun");
        set("coor/x",30);
        set("coor/y",0);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);
}
