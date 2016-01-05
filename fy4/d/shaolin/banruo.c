// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
Ϊ����Ӵ���Ħ������������������Ϊ��ɮ���������þ����ˣ����ĦԺ��
�޺��ò��У��������ֺ󱲵����书������ʤ����ĦԺ���ϣ�������������ס��
���в��������������������ţ���Сɳ��ר������
LONG
        );
        set("exits", ([ 
  "southeast" : __DIR__"xueshen",
  "southwest" : __DIR__"yangxing",
  "north": __DIR__"muren",
  "east": __DIR__"lao",
  "west" : __DIR__"meiyuan",
]));
        set("objects", ([
                __DIR__"npc/monk11" : 2,
       ]) );
	set("coor/x",0);
	set("coor/y",120);
	set("coor/z",20);
	setup();
}

int valid_leave(object me, string dir)
{

	if (dir == "north")
		return notify_fail("����ľ����װ�ޣ������ڽ����¿��š�\n");
	
	if (dir=="north" && me->query("family/master_id") =="damo")
        {
            tell_object(me,"������������Ħ��ʦ����������ǿ��ʤ,���Ƿ��ŵ�����Ϊ,�㻹������ô?\n");
            return notify_fail("");
        }

	if(dir == "north" && me->query("class") == "shaolin" 
                      && me->query("family/generation") > 10)
    	{
        /* shaolin students */

        
        if (me->query_skill("zen", 1) < 175 || me->query_skill("chanting", 1) < 200)
        {
            message_vision("һ�ɴ�����$N���˻�����
һ�����ϵ�����˵����ƾ���������Ϊ�Ͷ������������ܳ����֡�\n",me);
            return notify_fail("");
        }

        if (me->query("marks/muren_time") && (me->query("marks/muren_time") + 48 * 3600 > me->query("mud_age"))) {
            message_vision("һ�ɴ�����$N���˻�����
һ�����ϵ�����˵�����㲻��ǰ�հ���ľ�������ȥ���������������ɡ�\n",me);
            return notify_fail("");
        }

        me->set("marks/muren_time", me->query("mud_age"));

    }
    return 1;
}

