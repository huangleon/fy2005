// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��Ħ��");
        set("long", @LONG
���ѵ�ɽ��С·��������·��ҡҷ����Ӱ���͵��������Ĵ�Ħ�������ڳ���
���ϣ�����������ʯ����������⡰Ĭ���������ഫ���ڳ����Ħ�ڴ���ھ����
������������Ϊ����ʥ�أ�������ɮ��֮ٮٮ�߰��ش˵ء�����������Ƭ�̣�����
����嶥��
LONG
        );
	set("exits", ([ 
		"southeast" : __DIR__"talin",
		"westup" : __DIR__"wuru",
		"enter" : __DIR__"damocave",
	]));
	set("objects", ([
		__DIR__"npc/guardmonk" : 2,
	]));
	set("coor/x",64);
	set("coor/y",26);
	set("coor/z",0);
	setup();

}

int valid_leave(object obj, string dir){
	object monk;
	if(dir == "enter" && monk = present("guard monk", this_object())){
		if(obj->query("class") != "shaolin") {
			message_vision("$N����������������ֵ������֮��������������\n", monk);
			return notify_fail("");
		}
	}
	return 1;
}
