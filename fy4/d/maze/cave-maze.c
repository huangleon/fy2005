// silencer@fy4 workgroup 


inherit VRM_SERVER;

void create()
{
	// �Թ��������̳е�����ĵ������ơ�
	set_inherit_room(__DIR__"cave-room");

	//�Թ��ĳ��Ϳ� (5-100)
	set_maze_long(20,20);
	
	//�趨�Թ���λ�����
	set_maze_spacing(5);

	//�Թ��������npc.
	//note: this one is optional
//	set_maze_npcs(__DIR__"npc/w-sentry-1");

	//�Թ������ڷ��� npc �Ŀ�����(1-100)
	//note: this one is optional too, if not set, then default is 20 (1/5)
//	set_maze_npc_rate(100);

	//�Թ��ؽ�ʱ�� pass in integer ����Ϊ��λ
	//note: this one is optional, if not set then default is no refresh
	//if pass in 0, then means no refresh too.
	// this example means maze will be refreshed in 1 hour.
//	set_maze_refresh(3600);

	//��ڷ���(�����ڶ���)
	set_entry_dir("north");

	//�������������ӷ���
	set_link_entry_dir("north");

	//�������������ӵ�����
	set_link_entry_room(__DIR__"cave-entry");
	
	//��ڵ�����(��������link_entry_room���Ǹ���ʵroom������
	set_link_entry_room_x(0);
	set_link_entry_room_y(-100);
	set_link_entry_room_z(-10);
	

	//��������������ӷ���
	set_link_exit_dir("south");

	//��������������ӵ�����
	set_link_exit_room(__DIR__"cave-exit");

	//��ڷ��������
	set_entry_short("������");

	//��ڷ�������
	set_entry_desc(@LONG
�������ɽ���������ʯ����������̦޺����������ʪ�ֻ����������濴�˿���
��Լ��Щ���ߣ������Ǵ�ʯ����͸�����ģ���������˸���׻𡣴�˵�޵�֮���ڴ�
��֮ʱ���ĵ׵�а������ữ����֣�����ǲ��Ǿ������ǵ�����֮���أ�
LONG
);

	//���ڷ��������
	set_exit_short("����");

	//���ڷ�������
	set_exit_desc(@LONG
�ں��������Ӱ�к�Ȼ����Щ���⣬���������Ȼ������������˵��������
һյָ·�ĵơ���ֵ��ǣ��������Խ��Խ����������ȴԽ��Խ�ҵ����������˼�
�ĵƻ𣬶��Ƿ�ڣ����Ծ�Ĺ���㲻�ɻ�������һ��Ƥ���
LONG
);

	//�Թ�����Ķ�����
	set_maze_room_short("���");

	//�Թ����������������ж�������������ÿ����
	//���ʱ���������ѡ��һ����
	set_maze_room_desc(@LONG
һ���������ɽ�����ڳ�����һ���������ס������ʯ����������̦޺������
����ʪ�ֻ�����ʯ���ƺ����˹�����ģ������ܵ�ʯ�������ܿ�������ĺۼ�����
�ﲻʱ������ֵ��춯���ƺ��������ڿ��������ƺ���Ұ�޵Ĵ�Ϣ��������������
�ţ�������Щ��ǵ�ζ����
LONG
);

	// �Թ������Ƿ�Ϊ���ⷿ�䣿
	set_outdoors(0);
}
