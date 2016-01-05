inherit ROOM;

void create()
{
	set("short", "����ջ��");

	set("long", @LONG
һ�������������ͱڵ�ջ��������������֪ͨ��η���̧ͷ���Ͽ�ȥ��������
�ƣ�ɽ����Ũ�������������ɹ��֣�����ס�ջ�����ʧ�ޣ�ľ�ƻ����ϵĶϣ�
�۵��ۣ�һ��С�ľͲ���׹��������޵���Ԩ��ջ���ϲ���һ�������ε�ɽ����
LONG);

	set("type","road");
	set("exits",([
        "west":__DIR__"cliffroad2",
        "enter":__DIR__"chiyoudao",
        "southeast":__DIR__"cliffroad4",
	]) );
       set("outdoors", "wolfmount");
	set("objects",([
     		__DIR__"npc/toutuo":1,
    	]) );
	set("coor/x",40);
	set("coor/y",20);
	set("coor/z",-30);
	set("count",0);
	setup();
}

//	The reset function here is for chiyouku, since chiyouku is a rare-accessed room, the function
//	in that room could be unloaded thus stops working correctly.
//  No need now, we use boss system on chi you

/*
void reset(){
	object ob, room;
	int count;
	::reset();
	
	add("count",1);

	room=find_object(__DIR__"chiyouku");
	if (!objectp(room)) room=load_object(__DIR__"chiyouku");
	room->reset();
//	4*24*7, refresh every 7 days.
	if (query("count")<672+random(672)) return;
	
	set("count",0);
	
	
		
	room->set("long", @LONG
��������ɫ������ļ����䣬ɲ�Ǽ�Ũ�Ʒ���������������������������ɭ
�޹������Ȼ��ʮһ���С��һ�ľ������ľ���ߴ�ٳߣ���ΰ�������ж�
������֮�����������֮�ƣ���Ȼ�����ϹŴ�˵�Ĵ�����ȣ�����ͷ����Ȼ��һ��
���������𻪵ķ���û�����壻����ʮ�����񣬷ֱ�Ϊ�����ġ��֡��ҡ��ڡ��ݡ�
а���ޡ������ͳ��ĸ��������죬�ܹ����ӣ������������Զ�����������
Ĥ�ݡ�����������ɽ��Ұ����ɭɭ�׹ǣ������е������쳣����ÿһ�߰׹Ǿ�ͷ��
��Ⱦ��񣬾�����Ĥ�ݡ�
LONG);
	room->set("staff", 1);
	
}
*/

int valid_leave(object me, string dir)
{
	object *inv;
	object ob;
	object room;

	if (me->query("timer/insurance") + 259200 > time())
		return 1;

	if( userp(me))
	{
                switch(random(10))
		{
			case 0:
				message_vision("$N����һ��������������ջ���ϻ��˻Σ���\n",me);
				return notify_fail("���ã�û����ȥ��\n");
				break;
			case 1:
				inv = all_inventory(me);
				if(sizeof(inv)>=1)	
				{
					ob = inv[random(sizeof(inv))];
                    if (ob->query("no_drop") || ob->query("owner")
                    	|| ob->query_autoload() ) break;
					message_vision(ob->name()+"��$N���ϻ��˳���������������Ԩ��\n",me);
					destruct(ob);
				}
				return 1;
				break;
			case 2:
				message_vision("$N������ջ����ǰ����ϵػ���......\n",me);
				message_vision("$N��æ�������ϣ����ã����ڰ�ȫ��......\n",me);
				return 1;
				break;
			default:
				return 1;
				break;
		}
		return 1;
	}
	else
	return 1;
}
