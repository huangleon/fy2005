inherit __DIR__"no_killing_place";
void create()
{
    set("short", "С������");
    set("long", @LONG
�ӱ�������Ĳݵأ�����ˮ�ɳ���ǳǳ�İ��ߣ��������İڶ������治��
ˮ��Ҳ���ļ�������������ˮ���ƺ����ڳ���һ�׻���ĸ�����һ�����ɵ�С����
�������������Ӱ��Ķ����Ǳ��̵Ĳ�ƺ��������ֲ��һЩ������Լ�ɼ����侫�µ�
С��������䡣
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
        "west" : __DIR__"road5",
        "east" : __DIR__"bridge",
        ]));
	set("no_magic", 1);
    set("outdoors","taoyuan");
	set("coor/x",50);
	set("coor/y",0);
	set("coor/z",0);
    setup();
        replace_program( __DIR__"no_killing_place");
}


