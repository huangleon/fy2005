inherit __DIR__"no_killing_place";
void create()
{
    set("short", "ɽ�ֱ�Ե");
    set("long", @LONG
ϸ�ܵ�é�ݽ�������С�Ĺ�ľ�����棬��Щ��֪���Ĺ�ľ����ʮ��ïʢ���е�
���ŵ���ɫ��С�����еĽ���һ������ɫ�Ĺ�ʵ������������Լ�����Ա��ϳ���ľ
���е�С·������ǰ��ľ�ֽ�������˸ߴ����ľ��
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
        "west" : __DIR__"milin",
        "east" : __DIR__ "lawn",
        ]));

    set("outdoors","taoyuan");
	set("coor/x",30);
	set("coor/y",-10);
	set("coor/z",0);
    setup();
    replace_program(__DIR__"no_killing_place");
}
