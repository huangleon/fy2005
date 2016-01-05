#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�ձ�");
        set("long", @LONG
������ס����һ���ձڣ��ձڵ����Ը�����һյ�����ơ��ƹⲢ������������
�����㹻���������ձڣ�Ҳ���㹻�����ձ����滭�ŵ��Ǹ�Ů�ˡ�ˮ�߰��������
�ư�ķ������������������˼����С�������Ҳ�ڷ��衣��û����գ���û�����أ�
ֻ�з���������ͻ��档���ͷ����ڷ������֮�С������ǲ��Ǿ�����ħŮ��
LONG
        );
        set("exits", ([ 
		"west":  __DIR__"village2",
//		"east": __DIR__"andao1",
	]));
        set("item_desc", ([
        	"woman": MAG"��������㣬ֻ��һ����ɴ����������ɴ�����������ȱ����ң���û������
��Ӧ���ڵĵط���\n"NOR,
		"��ħŮ": MAG"��������㣬ֻ��һ����ɴ����������ɴ�����������ȱ����ң���û������
��Ӧ���ڵĵط���\n"NOR,
        	"Ů��": MAG"��������㣬ֻ��һ����ɴ����������ɴ�����������ȱ����ң���û������
��Ӧ���ڵĵط���\n"NOR,
		"�ձ�":		"�ձ��ϻ���һ��Ů�ˡ�\n",
	 ]));
	set("coor/x",80);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
}


void init()
{
       	add_action("do_push", "push");
}


void close_passage()
{
        object room;
        message("vision", "�ձ�������Ϣ����ת�˻�������ס�˰�����\n", this_object() );
        delete("exits/east");
}

int do_push(string arg)
{
        object obj, room;
        if(!arg || (arg != "��ħŮ" && arg != "woman" && arg !="Ů��")) {
                return 0;
        }
	if (query("exits/east"))
		return notify_fail("�ձ��Ѿ����ˡ�\n");
		message_vision(WHT"$N��������ħŮ����ĳ��һ����\n"NOR,this_player());
		message_vision("��ħŮ���˵�Ц�ݷ·�Ĩ����һ�������ʹ�ࡣ����������ٿ�������������һ�䣬
����С����������ǰӭȥ�������������ȵ�һ���ձ�Ҳ����䣬�����һ�����š�\n",this_player());
		set("exits/east",__DIR__"andao1");
        call_out("close_passage", 10);
        return 1;
}


void reset()
{
        ::reset();
        delete("exits/east");
}