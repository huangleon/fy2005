//All Rights Reserved 1998 Apstone, Inc.

inherit ROOM;

void create()
{
 set("short", "��ľ��");
 set("long",@LONG
������·������֦���߽���ľ���С����ӷǳ���������ʪ����������ˮ��̫��
��Ե�ʣ��������к���ζ�������������ô��һƬ��ľ�ָе��ǳ��Ծ��������ƺ�
����û��·�������˰��˸ߵ��Ӳݡ�
LONG);
	 set("exits", ([
	  	"north" : __DIR__"seaside2",
	 ]));
	 set("item_desc", ([
	    "bush" : "��Ƭ��ľ��̫����,Ҫ���ȥ����ֻ��Ӳ��ǰ����dash���ˡ�\n",
	    "��ľ��" : "��Ƭ��ľ��̫����,Ҫ���ȥ����ֻ��Ӳ��ǰ����dash���ˡ�\n",
	    "��ľ" : "��Ƭ��ľ��̫����,Ҫ���ȥ����ֻ��Ӳ��ǰ����dash���ˡ�\n",
	 ]));
	 set("outdoors", "bat");
	set("coor/x",1000);
	set("coor/y",-50);
	set("coor/z",0);
		setup();
}
void init()
{
    add_action("do_dash", "dash");
}

int do_dash( string arg )
{
	 object me,room;
	 me = this_player();
	 if(!arg || arg != "bush")
	  	return notify_fail("��Ҫ���Ķ�����\n");
	 if(me->query_str()<20 || me->query("force") < 300) {
		return notify_fail("���۵�����������Ҳû�д�����·����
����20����Ч������300��������\n");
	 }
	 room = load_object(__DIR__"lin2");
	 if(!objectp(room)) 
		return notify_fail("���۵�����������Ҳû�д�����·����\n");
	 message_vision("$Nʹ������ľ����һ�������һ����ͷ���˽�ȥ��\n",me);
	 me->move(room); 
	 me->delete("force");
	 return 1;
}
