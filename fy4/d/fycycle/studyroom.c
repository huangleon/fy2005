#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�鷿");
        set("long", @LONG
����һ�䲼�÷ǳ��Ž���鷿����ǽ����̴ľ������̯�Ÿ���û��ɵ�������
÷ͼ������ǽ�µ�С���Ϸ���һ���٣�ǽ�Ϲ���һ�����̻���һ�ѽ������ű�ǽ��
��������ϰ������顣
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"meihouse",
	]));

    set("indoors", "fengyun");
	set("coor/x",-320);
	set("coor/y",100);
	set("coor/z",0);
    setup();

}

void init(){
	add_action("do_push","push");
}

int do_push(string arg)
{
	object player;
	player = this_player();
	if (arg != "stone" && arg != "����ש")
	{
		return notify_fail("��Ҫ��ʲô��\n");
	}
	if (!player->query("marks/÷ɽ��"))
	{
		return notify_fail("����������������Ե�һ�黨��ש������ש��˿������\n");
	}
	
	if( !query("exits/down") ) 
	{
        message_vision("$N���ְ��˰��ǿ���ǽ����������Ե�һ�黨��ש����ܱ�ͻ��һ�֣�¶��һ���ص���ʯ��ֱͨ�ŵصס�\n",player);
		set("exits/down", __DIR__"groundroom");
        call_out("close_path", 2);
		return 1;
    } else {
		return notify_fail("����ש�Ѿ����ƿ��� \n");
	}
    return 1;
}
void close_path()
{
	if( !query("exits/down") ) return;
	message("vision","����ֻ����ĺ����ˡ�\n",this_object() );
	delete("exits/down");
}
int valid_leave(object player, string dir)
{
	if ( dir == "down" && (!player->query("marks/÷ɽ��")||player->query("combat_exp")<4000000)){
		return notify_fail("�㳯�¿��˿��������룬��֪������ʲô�����ǲ�Ҫð��Ϊ�\n");
	}
	return 1;
}